#include "Menu.h"

using namespace std;

int Menu::GameSelectMenu(vector<string> words, vector<string> definitions, vector<string> pronunciations)
{

	cout << endl<< "Select Game Type" << endl;
	cout << "1) Learn Words." << endl << "2) Learn Definitions." << endl << "0) Exit" << endl;
	cin >> selection;

	//user input decides what game to play or exit
	switch (selection)
	{
	case 1:
		//send to 1 game;
		wordGame.WordGame(words, definitions, pronunciations);
		return 1;
	case 2:
		//send to 2 game;
		wordGame.DefinitionGame(words, definitions, pronunciations);
		return 2;
	case 0:
		//send to exit;
		return 0;
	}
}