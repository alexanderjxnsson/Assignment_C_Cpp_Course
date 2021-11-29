/* declarations start */
#include "header/declarations.h"
/* std::vector<std::string> deleteSearchResult (std::string file_name, std::string search_term)
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
} */
/* declarations end */
int main() {
    /* init start */
    fileChecking();
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
            //addPlayer();
            theGame();
            break;
        case HIGHSCORE:
            showHighscoreList();
            std::cout<<"\nPress a button to exit the highscore list\n";
            system("pause");
            system("cls");
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