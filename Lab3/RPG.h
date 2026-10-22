//RPG.H
#ifndef RPG_H
#define RPG_H
#include <string>
using namespace std;
const int INVENTORY_SIZE = 10;
const float HIT_FACTOR = 0.05;
const int MAX_HITS_TAKEN = 3;
class RPG {
    public:
    //constructors
    RPG();
    RPG(string name, int hits_taken, float luck, float exp, int level);

    //mutators
    bool isAlive() const;
    void setHitsTaken(int new_hits);

    //accessor
    string getName() const;
    int getHitsTaken() const;
    float getLuck() const;
    float getExp() const;
    int getLevel() const;

    private:
        string name;
        int hits_taken;
        float luck;
        float exp;
        int level;
};
#endif

void RPG::attack(RPG * opponent){

    random_device rd;
    mt199937 gen(rd()); // seed with random
    uniform_real_distribution<double> dis(0.0, 1.0);

    float random_num = dis(gen);
    bool hit;
    if (random_num > HIT_FACTOR * opponent.getLuck){
        hit = true;
    }
    if (hit = true){
        updateHitsTaken(opponent);
    }
}

void RPG::printStats(){
    cout << "Name: ", name, "   Hits Taken: ", hits_taken, "  Luck: ", luck, "  Exp: ", exp, "  Level: ", level, "  Status: ", isAlive);

}

RPG::~RPG()
{
    
}