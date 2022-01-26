//
// Created by benja on 26/01/2022.
//

#ifndef GAME_UIHELPERS_H
#define GAME_UIHELPERS_H
#include<string>
#include<vector>

class GameManager;
class Player;

bool handleInput(GameManager &man, const std::string &line);
std::string pressEnterToContinue();
bool getConfirmation();

std::string isolator();
void printInputOptions();
void printCredits();

void insertNewPlayer(std::vector<Player> &playerList);
GameManager setupGame();


#endif //GAME_UIHELPERS_H
