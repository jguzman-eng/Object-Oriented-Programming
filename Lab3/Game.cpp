//Game.cpp
#include "Game.h"

Game::Game()
{
}

void Game::generatePlayers(int n)
{
    for (int i = 0; i < n; i++){
        players.push_back(new RPG());

        //rename players
        string new_name = "NPC_"+to_string(i);
        players[i]->setname(new_name);
        live_players.insert(i);
    }
}

int Game::selectPlayer(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, live_players.size() - 1);

    // Pick random index
    int randomIndex = dist(gen);

    //Advance iterator to that index
    set<int>::iterator it = live_players.begin();
    advance(it, randomIndex);
    
    int selectedIndex = *it;
    return selectedIndex;
}

void Game::endRound(RPG *winner, RPG *loser, int loserIndex){
    winner.hits_taken = 0;
    loser.loserIndex = 1;
    updateExpLevel(winner);
    cout << "NPC_X won against NPC_Y";
}

void Game::battleRound(){
    selectplayer() = playerIndex1;
    selectPlayer() = playerIndex2;

    if (playerIndex1 == playerIndex2){
        battleGround()
        return;
    }
    players[0] = RPG* player1;
    players[1]= RPG* player2;

    while (player1.isAlive = true){
        player1->attack(player2);
        player2->attack(player1);
    }

    if (player1.isAlive){
        endRound(player1);
    }
    if (player2.isAlive){
        endRound(player2);
    }

}

void Game::gameLoop(){
    while (isAlive > 0){
        battleGround();
    }
}
void Game::printFinalResults(){
    for (i = 0; i < players.size; i++){
    printStats(player[i]);
    }
}

Gamer::~Game()
{
}