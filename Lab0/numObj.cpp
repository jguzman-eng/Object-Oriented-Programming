#include <iostream>

using namespace std;

int main () {
    int int_example;
    float float_example;
    double double_example;
    char char_example;
    bool bool_example;

    cout << "int_example: " << sizeof(int_example) << endl;
    cout << "float_example: " << sizeof(float_example) << endl;
    cout << "double_example: " << sizeof(double_example) << endl;
    cout << "char_example: " << sizeof(char_example) << endl;
    cout << "bool_example: " << sizeof(bool_example) << endl;

    return 0;
}