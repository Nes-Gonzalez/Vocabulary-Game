#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include "Games.h"
#include "TextToSpeech.h"


using namespace std;

class Menu
{
public:
	int GameSelectMenu(vector<string>, vector<string>,vector<string>);
private:
	int selection;
	Games wordGame;
	Games definitionGame;

};

#endif