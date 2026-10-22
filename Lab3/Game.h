
#ifndef GAME_H
#define  GAME_H

Game();

public:
void generatePlayers(int n);
void endRound(RPG* winner, RPG* loser, int loserIndex);
void battleROund();
void gameLoop();
void printFInalResults;

private:
vector<RPG> players;
int live_players

~Game()
 
#endif