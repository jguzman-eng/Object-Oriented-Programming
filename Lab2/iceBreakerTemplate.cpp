#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<random>

using namespace std;

//------------------------PROTOTYPE-------------------------------------------
void promptFile(vector<string> &); 
void printVec(vector<string>);
int ranGen(int);
bool readFile(string filename, vector<string> & vec);
bool writeFile(string filename,const vector<string> & v0, const vector<string> & v1);

int main()
{
    vector<string> roster;
    vector<string> qBank;
    readFile("2310_F26_Rosters.csv", roster);    
    readFile("Questions.csv", qBank);
    // printVec(roster);
    // printVec(qBank);

    cout << "Size of roster: " << roster.size() << endl; 
    // cout << "Size of qBank: " << qBank.size() << endl;

    writeFile("Student_question_bank.csv", roster, qBank);


}

 /**
  * @brief generates a random index for the questions vector
  * 
  * @param questionsSize 
  * @return int 
  */
int ranGen(int questionsSize){
    // Learning: Source is AI
    //Step 1: Get an initial seed, old one uses the clock for a seed
    //this one uses my opearting system and hardware to generate a seed
    static random_device rd;
    //intialize the random number generator with the seed
    static mt19937 gen(rd());
    //defines the range of the random number generator
    uniform_int_distribution<int> distrib(0, questionsSize -1);
    return distrib(gen);

}

/**
 * @brief reads contents of filename and populates into vec
 * 
 * @param filename :string 
 * @param vec: vector<string> &
 */
bool readFile(string filename, vector<string> & vec) {

   ifstream inputFile(filename);

    //error handling
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file\n";
        return false;
    }

    string line;

    while (getline(inputFile, line)) {
        vec.push_back(line);
    }

    inputFile.close();
   return true;
}
/**
 * @brief writes to filename with the first column from v0, second column from v1
 * 
 * @param filename: string
 * @param v0: vector<string> (for students names)
 * @param v1: vector<string> (for questions)
 * 
*/
bool writeFile(string filename, const vector<string> & v0, const vector<string> & v1){

    ofstream outputFile(filename);
     if (!outputFile) {
        cout << "Error: Could not create data.csv" << endl;
        return false;
    }

    // write under the structure:
    // Student_Name, Question_#
    for(int i = 0; i < v0.size(); i++){
        outputFile << v0[i] << "," << v1[ranGen(v1.size())] << endl;
    }
    outputFile.close();
    return true;



}

//------------------------DECLARATIONS-------------------------------------------
/**
 * @brief prompts the user to give a file to read
 * 
 */
void promptFile(vector<string> & v){
    cout << "file to read?\n";
    string myFile = "";
    cin >> myFile;
    readFile(myFile, v);
}


/**
 * @brief prints out the elements in v
 * 
 * @param v: vector<string>
 */
void printVec(vector<string> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}