#ifndef GAMES_H
#define GAMES_H

#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include "TextToSpeech.h"

using namespace std;

class Games 
{
public:
	void WordGame(vector<string>, vector<string>,vector<string>);
	void DefinitionGame(vector<string>, vector<string>,vector<string>);
private:
	string input;
	int intInput;
	int random;
	int score;
	int total;
	int currentScore;
	int numberOfWords;
	int def1;
	int def2;
	int correctDef;
	TextToSpeech talk;
};

#endif 