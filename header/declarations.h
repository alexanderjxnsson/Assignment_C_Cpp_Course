/* declarations start */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>
#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif
std::string fileName = "players.csv", adminPasswordInpuit, adminPassword = "666", value, seperator = "==========================================================\n", playerToBeRemoved, deletePlayerChoice;
int menuChoice, gameGuess, winningNumber, maxGuess = 5, X = 0, sleepTime = 1000;
bool bMenuRunning = true, bAdminMenu = true, bAdminModeLogin = true, bFileChecking = true, bDeletePlayerMenu = false, bGameRunning = true;
enum choicesForMainMenu {PLAY = 1, HIGHSCORE, ADMIN, EXITGAME};
enum choicesForAdminMenu {DELETEPLAYER = 1, EMPTYHSLIST, EXITADMINMENU};
int guessingHistory[5];
std::fstream fout;
std::fstream fin;
std::fstream myFile;
void header();
void mainMenu();
void fileChecking();
void columnBanner();
void menu();
void addPlayer();
void theGame();
void adminMode();
void randomizer();
void showHighscoreList();
void adminDeletePlayer(std::string playerName);
void emptyHighscoreList();
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