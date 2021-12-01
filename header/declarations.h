/* declarations start */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>
std::string fileName = "players.csv", adminPasswordInpuit, adminPassword = "666",
value, seperator = "==========================================================\n",
playerToBeRemoved, deletePlayerChoice, fieldOne, fieldTwo, fieldThree, fieldFour,
seperator2 = "=======================\n";
int menuChoice, gameGuess, winningNumber, maxGuess = 5, X = 0, sleepTime = 1250, tempTries = 0, tempScore = 0, tempTotalTries = 0;
bool bMenuRunning = true, bAdminMenu = true, bAdminModeLogin = true, bFileChecking = true, bDeletePlayerMenu = false, bGameRunning = true;
enum choicesForMainMenu {PLAY = 1, HIGHSCORE, ADMIN, EXITGAME};
enum choicesForAdminMenu {DELETEPLAYER = 1, EMPTYHSLIST, EXITADMINMENU};
int guessingHistory[5];
std::ofstream fout;
std::ifstream fin;
//std::fstream myFile;
void ingameHeader();
void welcomHeader();
void mainMenu();
void fileChecking();
void columnBanner();
void menu();
void addPlayer();
void theGame();
void ingameTable();
void adminMode();
void randomizer();
void showHighscoreList();
void adminDeletePlayer(std::string playerName);
void emptyHighscoreList();
int settingTheScore(int a);
std::vector<std::string> readCsvFile (std::string file_name);
struct Players
{
    std::string playerName;
    std::string playerCity;
    int playerScore = 0;
    int numberOfTries = 0;
}tPlayer;
std::vector<Players> vPlayers;
/* declarations end */