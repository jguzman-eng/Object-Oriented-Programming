#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pokemon{

    public:
        Pokemon();
        Pokemon(string name, int hp, int attack, int defense, vector<string> type);

        void speak();
        void printStats();

    protected:
        string name;
        int hp;
        int attack;
        int defense;
        vector<string> type;
};

#endif