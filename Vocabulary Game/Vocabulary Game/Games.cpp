#include "Games.h"



void Games::WordGame(vector<string> words, vector<string> definitions)
{
	cout << "Word Game!!" << endl << endl;
	cout << "press enter to begin." << endl;
	system("PAUSE");
	srand(time(NULL));
	while (input != "exit")
	{
		random = rand() % words.size();
		talk.say()
		
	}
}
void Games::DefinitionGame(vector<string> words, vector<string> definitions)
{

}
