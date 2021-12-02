#include "declarations.h"
/*functions start */
void fileChecking()
{
    fin.open("players.csv", std::ios_base::app);
    if (fin.is_open())
    {
        std::cout<<"File is OK, game loading. . .\n";
        while ( getline(fin, fieldOne, ','))
	    {
            getline(fin, fieldTwo, ',');
            getline(fin, fieldThree, ',');
            getline(fin, fieldFour, '\n');
            tPlayer.playerName = fieldOne;
            tPlayer.playerCity = fieldTwo;
            tPlayer.playerScore = stoi(fieldThree);
            tPlayer.numberOfTries = stoi(fieldFour);
            vPlayers.push_back(tPlayer);
        }
        fin.close();
        Sleep(2000);
        system("cls");
    }
    else
    {
        std::cout<<"File is not OK, closing the application!\n";
        Sleep(4000);
        system("cls");
        bMenuRunning = false;
    }
}
void welcomeHeader()
{
    std::cout << "#" << std::right << std::setfill('=') << std::setw(50) << "#" << std::endl
                << "#" << std::right << std::setfill(' ') << std::setw(50) << "#" << std::endl
                << "#" << std::left << std::setfill(' ') << std::setw(9) << " " << std::right 
                << std::setw(26) << "Welcome The End Game!" << std::right << std::setw(15) << "#" << std::endl
                << "#" << std::right << std::setfill(' ') << std::setw(50) << "#" << std::endl
                << "#" << std::right << std::setfill('=') << std::setw(50) << "#" << std::endl
                <<std::setfill(' ');
}
void ingameHeader()
{
    std::cout << "#" << std::right << std::setfill('=') << std::setw(50) << "#" << std::endl
                << "#" << std::right << std::setfill(' ') << std::setw(50) << "#" << std::endl
                << "#" << std::left << std::setfill(' ') << std::setw(9) << " " << std::right 
                << std::setw(26) << "Time for some guessing!" << std::right << std::setw(15) << "#" << std::endl
                << "#" << std::right << std::setfill(' ') << std::setw(50) << "#" << std::endl
                << "#" << std::right << std::setfill('=') << std::setw(50) << "#" << std::endl
                <<std::setfill(' ');
}
void adminHeader()
{
    std::cout << "#" << std::right << std::setfill('=') << std::setw(50) << "#" << std::endl
                << "#" << std::right << std::setfill(' ') << std::setw(50) << "#" << std::endl
                << "#" << std::left << std::setfill(' ') << std::setw(9) << " " << std::right 
                << std::setw(26) << "You're logged in as admin!" << std::right << std::setw(15) << "#" << std::endl
                << "#" << std::right << std::setfill(' ') << std::setw(50) << "#" << std::endl
                << "#" << std::right << std::setfill('=') << std::setw(50) << "#" << std::endl
                <<std::setfill(' ');
}
void highscoreHeader()
{
    std::cout << "#" << std::right << std::setfill('=') << std::setw(57) << "#" << std::endl
                << "#" << std::right << std::setfill(' ') << std::setw(57) << "#" << std::endl
                << "#" << std::left << std::setfill(' ') << std::setw(9) << " " << std::right 
                << std::setw(26) << "Highscore!" << std::right << std::setw(22) << "#" << std::endl
                << "#" << std::right << std::setfill(' ') << std::setw(57) << "#" << std::endl
                << "#" << std::right << std::setfill('=') << std::setw(57) << "#" << std::endl
                <<std::setfill(' ');
}
void menu()
{
    
    welcomeHeader();
    std::cout<<"Enter what you want to do:\n";
    std::cout<<"1. Play\n2. See highscore list\n3. Enter admin mode\n4. Exit the game\n";
}
void mainMenu()
{
    while (bMenuRunning == true)
    {
        menu();
        std::cin>>menuChoice;
        switch (menuChoice)
        {
        case PLAY:
            std::cout<<"\nLoading the game. . .\n";
            Sleep(sleepTime);
            system("cls");
            theGame();
            break;
        case HIGHSCORE:
            system("cls");
            highscoreHeader();
            columnBanner();
            showHighscoreList();
            std::cout<<"\nPress a button to exit the highscore list!\n";
            system("pause");
            system("cls");
            break;
        case ADMIN:
            adminMode();
            break;
        case EXITGAME:
            std::cout<<"\nYou chose to exit the application!\n";
            //myFile.close();
            bMenuRunning = false;
            break;
        default:
            std::cout<<"\nPlease enter a valid number!\n";
            Sleep(2000);
            system("cls");
            break;
        }
    }
}
void ingameTable()
{
    std::cout<<seperator2
        <<std::left
        <<"|| " <<std::setw(8)<<"Score"<<" || "
        <<std::setw(8)<<"Tries ||"<<std::endl
        <<seperator2;
    std::cout
        <<"|| " << std::left << std::setw(8);
        std::cout << tempScore << " || "
        <<std::setw(5) << displayAllTries << " ||"
        <<std::endl<<seperator2;
}
void columnBanner()
{
    std::cout<<seperator
        <<std::left
        <<"|| " <<std::setw(12)<<"Name"<<" || "
        <<std::setw(15)<<"City"<<" || "
        <<std::setw(8)<<"Points"<<" || "
        <<std::setw(2)<<"Tries ||"<<std::endl
        <<seperator;
}
int randomizer(int a) {
    int random;
    srand(time(0));
    return random = rand() % 10 + 1;
}
void theGame()
{
    //Resetting values for new player
    bGameRunning = true;
    tempTries = 0;
    tempScore = 0;
    tempTotalTries = 0;
    displayAllTries = 0;
    std::cin.ignore();
    std::cout<<"Rules:\n- Guess a number between 1 and 10.\n- You have 5 tries before the game ends.\nYes, it's that simple\nLets's GO!\n\n";
    std::cout<<"Enter the name of player: ";    std::getline(std::cin, tPlayer.playerName);
    std::cout<<"Enter hometown of player: ";    std::getline(std::cin, tPlayer.playerCity);
    std::cout<<"\nLet's play!! Game loading. . .\n";
    Sleep(sleepTime);
    system("cls");
    winningNumber = randomizer(winningNumber);
    ingameHeader();
    ingameTable();
    while (bGameRunning == true)
    {
        
        std::cout<<std::endl<<winningNumber<<std::endl;
        
        std::cout<<"Your guess: ";
        std::cin>>gameGuess;
        if (gameGuess == winningNumber)
        {
            displayAllTries++;
            tempTries++;
            tempScore += settingTheScore(tempTries);
            system("cls");
            ingameHeader();
            ingameTable();
            std::cout<<"\nCONGRATZ, YOU GOT IT!\n";
            std::cout<<"\nDo you want to play again?\n1. Yes\n2. No\n";
            std::cin>>menuChoice;
            switch (menuChoice)
            {
                case 1:
                    std::cout<<"\nWe will clear the screen and restart the game!\n";
                    tempTotalTries += tempTries;
                    tempTries = 0;
                    X = 0;
                    winningNumber = randomizer(winningNumber);
                    Sleep(sleepTime);
                    system("cls");
                    ingameHeader();
                    ingameTable();
                    std::cout<<"\nThe number has been randomized, GUESS!\n";
                    break;
                case 2:
                    std::cout<<"\nYou chose not to play again, you will be exiting to the main menu! Thanks for playing!\n";
                    tempTotalTries += tempTries;
                    tPlayer.playerScore = tempScore;
                    tPlayer.numberOfTries = tempTotalTries;
                    fout.open("players.csv", std::ofstream::app);
                    fout    << tPlayer.playerName << ","
                            << tPlayer.playerCity << ","
                            << tPlayer.playerScore << ","
                            << tPlayer.numberOfTries << "\n";
                    fout.close();
                    vPlayers.push_back(tPlayer);
                    std::cout<<"\nPlayer has been added to the highscore list!\n";
                    Sleep(sleepTime);
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
            displayAllTries++;
            tempTries++;
            guessingHistory[X] = gameGuess;
            X++;
            system("cls");
            ingameHeader();
            ingameTable();
            std::cout<<"Guessing history: ";
            for (int i = 0; i < tempTries; i++)
            {
                std::cout<<"["<<guessingHistory[i]<<"]";
            }
            if (gameGuess > winningNumber)
            {
                std::cout<<"\nYour guess was higher than the secret number!\n";
            }
            else if (gameGuess < winningNumber)
            {
                std::cout<<"\nYour guess was lower than the secret number!\n";
            }
            
            if (tempTries == maxGuess)
            {
                std::cout<<"\n\nYou've reached the number of tries, you lost!\nYou will be exiting to the main menu.\nSee you soon!\n";
                tPlayer.playerScore = tempScore;
                tPlayer.numberOfTries = tempTotalTries;
                fout.open("players.csv", std::ofstream::app);
                fout    << tPlayer.playerName << ","
                        << tPlayer.playerCity << ","
                        << tPlayer.playerScore << ","
                        << tPlayer.numberOfTries << "\n";
                fout.close();
                vPlayers.push_back(tPlayer);
                X = 0;
                std::cout<<"\nPlayer has been added to the highscore list!\n\nLoading main menu. . .";
                
                Sleep(3500);
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
int settingTheScore(int tries)
{
    int score= 0;
    if (tries == 1)
    {
        return score += 50;
    }
    else if (tries == 2)
    {
        return score += 35;
    }
    else if (tries == 3)
    {
        return score += 20;
    }
    else if (tries == 4)
    {
        return score += 15;
    }
    return score += 5;

}
void showHighscoreList()
{
    
    fin.open(fileName, std::ifstream::in);
    vPlayers.clear();
    while ( getline(fin, fieldOne, ','))
	    {
            getline(fin, fieldTwo, ',');
            getline(fin, fieldThree, ',');
            getline(fin, fieldFour, '\n');
            tPlayer.playerName = fieldOne;
            tPlayer.playerCity = fieldTwo;
            tPlayer.playerScore = stoi(fieldThree);
            tPlayer.numberOfTries = stoi(fieldFour);
            vPlayers.push_back(tPlayer);
        }
    fin.close();
    for (int i = 0; i < vPlayers.size(); i++)
    {
        std::cout
        <<"|| " << std::left << std::setw(12) << vPlayers[i].playerName<<" || "
        <<std::setw(15) <<vPlayers[i].playerCity<<" || "
        <<std::setw(8)<<vPlayers[i].playerScore<<" || "
        <<std::setw(5)<<vPlayers[i].numberOfTries<<" ||"
        <<std::endl<<seperator;
    }
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
        adminHeader();
        std::cout<<"What do you want to do?\n";
        std::cout<<"1. Delete person in highscore list\n2. Empty the highscore list\n3. Exit admin mode\n";
        std::cin>>menuChoice;
        switch (menuChoice)
        {
            case DELETEPLAYER:
                system("cls");
                columnBanner();
                showHighscoreList();
                std::cout<<"\nEnter name of the player you want to remove or enter 'cancel': ";
                std::cin>>playerToBeRemoved;
                if (playerToBeRemoved == "cancel")
                {
                    std::cout<<"\nYou chose to cancel, exiting. . . \n";
                    Sleep(sleepTime);
                    system("cls");
                }
                else
                {
                    adminDeletePlayer(playerToBeRemoved);
                }
                break;
            case EMPTYHSLIST:
                emptyHighscoreList();
                break;
            case EXITADMINMENU:
                std::cout<<"\nYou chose to exit admin mode!\nLoading main menu. . .\n";
                bAdminMenu = false;
                bAdminModeLogin = false;
                //myFile.close();
                Sleep(sleepTime);
                system("cls");
                break;
            default:
                std::cout<<"\nPlease enter a valid number!\n";
                Sleep(sleepTime);
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
    std::cout<<"\nPlayer data has been removed! Resetting screen. . .\n";
    Sleep(sleepTime);
    system("cls");
}
void emptyHighscoreList()
{
    vPlayers.clear();
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
                Sleep(sleepTime);
                system("cls");
                break;
            case 2:
                std::cout<<"\nYou chose no!\nResetting screen. . .";
                bDeletePlayerMenu = false;
                Sleep(sleepTime);
                system("cls");
                break;
            default:
                std::cout<<"\nPlease enter a correct command!\n";
                break;
        }
    }
}
/* functions end */