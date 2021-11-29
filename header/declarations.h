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
std::string fileName = "players.csv", adminPasswordInpuit, adminPassword = "666", value, seperator = "-----------------------------", playerToBeRemoved, deletePlayerChoice;
int menuChoice, gameGuess, winningNumber, maxGuess = 5;
bool bMenuRunning = true, bAdminMenu = true, bAdminModeLogin = true, bFileChecking = true, bDeletePlayerMenu = false, bGameRunning = true;
enum choicesForMainMenu {PLAY = 1, HIGHSCORE, ADMIN, EXITGAME};
enum choicesForAdminMenu {DELETEPLAYER = 1, EMPTYHSLIST, EXITADMINMENU};
std::string displaynumberOfTries [5];
std::fstream fout;
std::fstream fin;
std::fstream myFile;
void fileChecking();
void menu();
void addPlayer();
void theGame();
void adminMode();
void randomizer();
void showHighscoreList();
void adminDeletePlayer(std::string playerName);
void emptyHighscoreList();
std::vector<std::string> readRecordFromFile (std::string file_name);
struct Players
{
    std::string playerName;
    std::string playerCity;
    int playerScore = 0;
    int numberOfTries = 0;
}tPlayer;
std::vector<Players> vPlayers;
/* declarations end */

/*functions start */
void fileChecking()
{
    while (bFileChecking == true)
    {
        fin.open("players.csv", std::ios_base::app);
        if (fin.is_open())
        {
            int sec = 3;
            std::cout<<"File is OK, game loading. . .\n";
            fin.close();
            bFileChecking = false;
            Sleep(2500);
            system("cls");
        }
        else
        {
            std::cout<<"File is not OK, closing the application!\n";
            Sleep(4000);
            system("cls");
            bFileChecking = false;
            bMenuRunning = false;
        }
    }
}
void menu()
{
    std::cout<<"Welcome to the end game!\n";
    std::cout<<"Enter what you want to do:\n";
    std::cout<<"1. Play\n2. See highscore list\n3. Enter admin mode\n4. Exit the game\n";
}
int randomizer(int a) {
    int random;
    srand(rand() ^ time(NULL));
    return random = rand() % 10;
}
/* void addPlayer()
{
    fout.open("players.csv", std::ios::out | std::ios::app);
    std::cin.ignore();
    std::cout<<"Enter name of player: ";    std::getline(std::cin, tPlayer.playerName);
    std::cout<<"Enter city of player: ";    std::getline(std::cin, tPlayer.playerCity);

    fout    << tPlayer.playerName << ","
            << tPlayer.playerCity << ","
            << tPlayer.playerScore << ", "
            << tPlayer.numberOfTries << "\n";
    std::cout<<"\nPlayer has been added to the highscore list!\n";
    fout.close();
    Sleep(2500);
    system("cls"); 
} */
void theGame()
{
    fout.open("players.csv", std::ios::out | std::ios::app);
    std::cin.ignore();
    std::cout<<"Enter name of player: ";    std::getline(std::cin, tPlayer.playerName);
    std::cout<<"Enter city of player: ";    std::getline(std::cin, tPlayer.playerCity);
    std::cout<<"\nLet's play!! Game loading. . .\n";
    Sleep(2500);
    system("cls");
    std::cout<<"Rules:\n- Guess a number between 0 and 10.\n- You have 5 tries before the game ends.\nYes, it's that simple\nLets's GO!\n";
    bGameRunning = true;
    tPlayer.numberOfTries = 0;
    tPlayer.playerScore = 0;
    winningNumber = randomizer(winningNumber);
    while (bGameRunning == true)
    {
        std::cout<<winningNumber<<std::endl;
        std::cout<<"\nThe number has been randomized, GUESS!\n";
        std::cout<<"Your guess: ";
        std::cin>>gameGuess;
        if (gameGuess == winningNumber)
        {
            std::cout<<"\nCONGRATZ, YOU GOT IT!\n";
            tPlayer.playerScore += 1;
            tPlayer.numberOfTries +=1;
            std::cout<<"\nDo you want to play again?\n1. Yes\n2. No\n";
            std::cin>>menuChoice;
            switch (menuChoice)
            {
            case 1:
                std::cout<<"\nWe will clear the screen and restart the game!\n";
                Sleep(2500);
                system("cls");
                break;
            case 2:
                std::cout<<"\nYou chose not to play again, you will be exiting to the main menu! Thanks for playing!\n";
                fout    << tPlayer.playerName << ","
                        << tPlayer.playerCity << ","
                        << tPlayer.playerScore << ","
                        << tPlayer.numberOfTries << "\n";
                vPlayers.push_back(tPlayer);
                std::cout<<"\nPlayer has been added to the highscore list!\n";
                fout.close();
                Sleep(2500);
                system("cls"); 
                bGameRunning = false;
                break;
            default:
                std::cout<<"\nPlease enter a correct value!\n";
                break;
            }
        }
        else if (gameGuess != winningNumber)
        {
            std::cout<<"\nSorry, please try again!\n";
            tPlayer.numberOfTries += 1;
            std::cout<<"Tries: ";
            for (int i = 1; i <= tPlayer.numberOfTries; i++)
            {
                std::cout<<"["<<i<<"]";
            }
            
            if (tPlayer.numberOfTries == maxGuess)
            {
                std::cout<<"\n\nYou've reached the number of tries, you lost!\nYou will be exiting to the main menu.\nSee you soon!\n";
                fout    << tPlayer.playerName << ","
                        << tPlayer.playerCity << ","
                        << tPlayer.playerScore << ","
                        << tPlayer.numberOfTries << "\n";
                vPlayers.push_back(tPlayer);
                std::cout<<"\nPlayer has been added to the highscore list!\n";
                fout.close();
                Sleep(2500);
                system("cls"); 
                bGameRunning = false;
            }
        }
        else if (gameGuess > 10 || gameGuess < 0)
        {
            std::cout<<"\nPlease enter a number between 0 and 10!\n";
        }
    }
}
void showHighscoreList()
{
    std::vector<std::string> vDisplayHighscoreList = readRecordFromFile(fileName);
}
void adminMode()
{
    //Logging in
    bAdminModeLogin = true;
    while (bAdminModeLogin == true)
    {
        std::cout<<"Enter the admin password: ";
        std::cin>>adminPasswordInpuit;
        if (adminPasswordInpuit == adminPassword)
        {
            std::cout<<"\nAdmin mode activated!\nLoading. . .\n";
            bAdminMenu = true;
            bAdminModeLogin = false;
            Sleep(2000);
            system("cls");
        }
        else
        {
            std::cout<<"\nIncorrect password, try again\n";
            Sleep(2000);
        }
    }
    //If login successful
    while (bAdminMenu == true)
    {
        std::cout<<"What do you want to do?\n";
        std::cout<<"1. Delete person in highscore list\n2. Empty the highscore list\n3. Exit admin mode\n";
        std::cin>>menuChoice;
        switch (menuChoice)
        {
        case DELETEPLAYER:
            showHighscoreList();
            std::cout<<"\nEnter name of the player you want to remove: ";
            std::cin>>playerToBeRemoved;
            adminDeletePlayer(playerToBeRemoved);
            break;
        case EMPTYHSLIST:
            emptyHighscoreList();
            break;
        case EXITADMINMENU:
            std::cout<<"\nYou chose to exit admin mode!\nLoading main menu. . .\n";
            bAdminMenu = false;
            bAdminModeLogin = false;
            myFile.close();
            Sleep(2500);
            system("cls");
            break;
        default:
            std::cout<<"\nPlease enter a valid number!\n";
            Sleep(2500);
            system("cls");
            break;
        }
    }
}
void adminDeletePlayer(std::string playerName)
{
    std::string line;
    std::ifstream fin;
    std::ofstream fout;
    fin.open("players.csv", std::ios::in);
    fout.open("new.csv", std::ios::out | std::ios::app);
    std::vector<std::string> lines;
    while (std::getline(fin, line))
    {
        if (line.find(playerName) == std::string::npos)
        {
            fout << line << std::endl;
        }
    }
    fout.close();
    fin.close();
    std::remove("players.csv");
    std::rename("new.csv", "players.csv");
    std::cout<<"\nPlayer data has been removed!\n";
    Sleep(2500);
    system("cls");
}
void emptyHighscoreList()
{
    std::cout<<"\nAre you sure you want to empty the highscore list?\n1. Yes\n2. No\n";
    bDeletePlayerMenu = true;
    while (bDeletePlayerMenu == true)
    {
        std::cin>>menuChoice;
        switch (menuChoice)
        {
        case 1:
            std::cout<<"\nEmptying list. . .";
            fout.open("players.csv", std::ofstream::out | std::ofstream::trunc);
            fout.close();
            bDeletePlayerMenu = false;
            Sleep(2500);
            system("cls");
            break;
        case 2:
            std::cout<<"\nYou chose no!\nResetting. . .";
            bDeletePlayerMenu = false;
            Sleep(2500);
            system("cls");
            break;
        default:
            std::cout<<"\nPlease enter a correct command!\n";
            break;
        }
    }
}
std::vector<std::string> readRecordFromFile (std::string file_name)
{
	std::vector<std::string> record;
	std::ifstream file;
	file.open(fileName);
	std::string fieldOne, fieldTwo, fieldThree, fieldFour;

	while ( getline(file, fieldOne, ','))
	{
		getline(file, fieldTwo, ',');
        getline(file, fieldThree, ',');
        getline(file, fieldFour, '\n');

		std::cout << fieldOne << "\t"
                  << fieldTwo << "\t"
                  << fieldThree << "\t"
                  << fieldFour << std::endl;
	}
	file.close();
	return record;
}
/* functions end */