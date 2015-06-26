#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Menu.h"

using namespace std;

void main()
{
	ifstream input("WordInput.txt");
	vector<string> wordsList;
	vector<string> definitions;
	string tempLineHolder;
	int userInput;

	//reading file to get all words and definitions
	while (getline(input,tempLineHolder))
	{
		wordsList.push_back(tempLineHolder);

		getline(input, tempLineHolder);
		definitions.push_back(tempLineHolder);
	}

	cout << "Vocabulary Game" << endl;
	
	Menu menu;
	while(menu.GameSelectMenu()!=0);
}