/* declarations start */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <time.h>
#include <string>
std::string fileName = "players.csv", adminPasswordInpuit, adminPassword = "666", value, seperator = "-----------------------------";
int menuChoice, adminMenuChoice, idTracker = 0;
bool bMenuRunning = true, bAdminMenu = true, bAdminModeLogin = true;
enum choicesForMenu {PLAY = 1, HIGHSCORE, ADMIN, EXITGAME};
enum choicesForAdminMenu {DELETEPLAYER = 1, EXITADMINMENU};
std::fstream fout;
std::fstream fin;
std::fstream myFile;
void menu();
void addPlayer();
void theGame();
void adminMode();
void randomizer();
void deletePlayerHsList();
void showHighscoreList();
struct Players
{
    std::string playerName;
    std::string playerCity;
    int Playerscore;
}tPlayer;
std::vector<std::string> vPlayers;
/* bool writeRecordToFile (std::string file_name, std::string field_one, std::string field_two, std::string field_three, std::string field_four)
{
	std::ofstream file;
	file.open(fileName, std::ios_base::app);	//
	//file.open(file_name, ios::trunc); 		// over-write file
	file << field_one << ";" << field_two << ";" << field_three << field_four << std::endl;
	file.close();

	return 0;	
} */

void adminDeletePlayer(std::string token)
{
    std::string line;
    std::fstream fin;
    std::fstream fout;
    fin.open("players.csv", std::ios::in);
    fout.open("new.csv", std::ios::out | std::ios::app);
    //std::cin>>token;
    std::vector<std::string> lines;
    while (getline(fin, line))
    {
        if (line.find(token) == std::string::npos)
        {
            fout << line << std::endl;
        }
    }
    fout.close();
    fin.close();
    remove("players.csv");
    rename("new.csv", "players.csv");
    std::cout<<"\nPlayer and player data has been removed!\n";
}



std::vector<std::string> deleteSearchResult (std::string file_name, std::string search_term)
{
	std::vector<std::string> record;
	std::ifstream file;
	file.open(fileName);
	bool found_record = false;
	std::string field_one, field_two, field_three, line, word;

    while ( getline(file, field_one, ',') && !found_record)
	{
		getline(file, field_two, ',');
		getline(file, field_three, '\n');

		std::cout << field_one<< "\t"
                  << field_two << "\t"
                  << field_three << std::endl;


        if(field_one == search_term)
		{
			found_record = true; 
			record.push_back(field_one);
			record.push_back(field_two);
			record.push_back(field_three); 
		}
	}
	file.close();
	return record;
}

std::vector<std::string> readRecordFromFile (std::string file_name)
{
	std::vector<std::string> record;
	std::ifstream file;
	file.open(fileName);
	std::string field_one, field_two, field_three;

	while ( getline(file, field_one, ','))
	{
		getline(file, field_two, ',');
        getline(file, field_three, '\n');

		std::cout << field_one<< "\t"
                  << field_two << "\t"
                  << field_three << std::endl;
	}

	file.close();
	return record;
}
/* declarations end */

int main() {
    /* init start */
    fin.open("players.csv", std::ios_base::app);
    if (fin.is_open())
    {
        int sec = 3;
        std::cout<<"File is good, proceed!\n";
        system("pause");
        system("cls");
    }
    else
    {
        std::cout<<"File is not OK, exiting the application!\n";
        system("pause");
        system("cls");
        bMenuRunning = false;
    }

    /* init end */
    while (bMenuRunning == true)
    {
        menu();
        std::cin>>menuChoice;
        switch (menuChoice)
        {
        case PLAY:
            std::cout<<"\nThe game will start\n";
            system("pause");
            system("cls");
            addPlayer();
            theGame();
            break;
        case HIGHSCORE:
            showHighscoreList();
            break;
        case ADMIN:
            adminMode();
            break;
        case EXITGAME:
            std::cout<<"\nYou chose to exit the application\n";
            myFile.close();
            bMenuRunning = false;
            break;
        default:
            std::cout<<"\nPlease enter a valid number\n";
            system("pause");
            system("cls");
            break;
        }
    }
    


    


}

/* functions start */
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
void addPlayer()
{
    fout.open("players.csv", std::ios::out | std::ios::app);
    std::cin.ignore();
    std::cout<<"Enter name of player: ";    std::getline(std::cin, tPlayer.playerName);
    std::cout<<"Enter city of player: ";    std::getline(std::cin, tPlayer.playerCity);
    idTracker++;
    fout    << tPlayer.playerName << ","
            << tPlayer.playerCity <<","
            << tPlayer.Playerscore << "\n";
    std::cout<<"\nPlayer has been created, proceeding to game!\n";
    fout.close();
    system("pause");
    system("cls"); 
}
void theGame()
{

}

void showHighscoreList()
{
    std::vector<std::string> Result = readRecordFromFile(fileName);
    std::cout<<"\nPress a button to exit the highscore list\n";
    system("pause");
    system("cls");
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
            std::cout<<"\nAdmin mode activated!\n";
            bAdminMenu = true;
            bAdminModeLogin = false;
            system("pause");
            system("cls");
            
        }
        else
        {
            std::cout<<"\nIncorrect password, try again\n";
            system("pause");
            system("cls");
        }
    }
    //If login successful
    while (bAdminMenu == true)
    {
        std::cout<<"What do you want to do?\n";
        std::cout<<"1. Delete person in highscore list\n2. Exit admin mode\n";
        std::cin>>adminMenuChoice;
        switch (adminMenuChoice)
        {
        case DELETEPLAYER:
            deletePlayerHsList();
            break;
        case EXITADMINMENU:
            std::cout<<"\nYou chose to exit admin mode!\n";
            bAdminMenu = false;
            bAdminModeLogin = false;
            myFile.close();
            system("pause");
            system("cls");
            break;
        default:
            std::cout<<"\nPlease enter a valid number!\n";
            system("pause");
            system("cls");
            break;
        }
    }

}

void deletePlayerHsList()
{
    std::vector<std::string> vDisplayResult = readRecordFromFile(fileName);
    std::cout<<"\nEnter name of the player you want to remove: ";
    std::string playerToBeRemoved;
    std::cin>>playerToBeRemoved;
    adminDeletePlayer(playerToBeRemoved);
}



/*functions end */
