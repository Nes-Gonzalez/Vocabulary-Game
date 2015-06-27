#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Menu.h"

using namespace std;

int main()
{
	
	vector<string> wordsList;
	vector<string> definitions;
	vector<string> pronunciations;
	string tempLineHolder;
	int userInput;

	//reading file to get all words and definitions (converting to wstring for text to speech)
	ifstream input("WordInput.txt");

	//skipping information lines on text file
	for (int i = 0; i < 5;i++)
		getline(input, tempLineHolder);

	if (input.is_open())
	{
		while (getline(input, tempLineHolder))
		{
			wordsList.push_back(tempLineHolder);

			getline(input, tempLineHolder);
			pronunciations.push_back(tempLineHolder);

			getline(input, tempLineHolder);
			definitions.push_back(tempLineHolder);
		}
	}
	else
	{
		cout << "Failed to open input file, exiting...";
		system("PAUSE");
		return 0;

	}

	cout << "Vocabulary Game" << endl;
	
	//running menu and game
	Menu menu;
	while(menu.GameSelectMenu(wordsList,definitions,pronunciations)!=0);
	return 0;
}