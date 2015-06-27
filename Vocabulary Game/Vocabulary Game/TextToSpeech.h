#ifndef TEXTTOSPEECH_H
#define TEXTTOSPEECH_H

#include <iostream>
#include "stdafx.h"
#include <sapi.h>
#include <string>

using namespace std;

class TextToSpeech
{
public:
	bool say(string);
};

#endif