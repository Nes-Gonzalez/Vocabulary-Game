#include "Menu.h"

using namespace std;

int Menu::GameSelectMenu(vector<string> words,vector<string> definitions)
{
	cout << "Select Game Type" << endl;
	cout << "1) Learn Words." << endl << "2) Learn Definitions." << endl << "0) Exit" << endl;
	cin >> selection;
	switch (selection)
	{
	case 1:
		//send to 1 game;
		wordGame.WordGame(words, definitions);
		return 1;
	case 2:
		//send to 2 game;
		return 2;
	case 0:
		//send to exit;
		return 0;
	}
}