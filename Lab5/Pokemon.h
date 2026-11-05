#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pokemon{
    public:
        // Constructors
        Pokemon();
        Pokemon(string name, int hp, int attack, int defense, vector<string> type);
        //Mutator Funtions
        virtual void speak();
        // Accessor Functions
        virtual void printStats();

    protected:
        string name;
        int hp;
        int attack;
        int defense;
        vector<string> type;
};
#endif