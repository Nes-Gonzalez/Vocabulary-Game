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
	int random;
	int score=0;
	int total=0;
	int currentScore;
	int numberOfWords=0;
	TextToSpeech talk;
};

#endif 