//main.cpp
#include <iostream>
#include "RPG.h"
using namespace std;

int main() 
{
    Game::Game();
    int num_players = 10;
    generatePLayers(num_players);
    gameLoop();
    printFinalResult();

    return 0;
}