#include "TextToSpeech.h"

bool TextToSpeech::say(string wordToSay)
{
	//convert string to wstring to use with speech function
	wstring wstr(wordToSay.begin(), wordToSay.end());

	ISpVoice * pVoice = NULL;

	if (FAILED(::CoInitialize(NULL)))
		return FALSE;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
	if (SUCCEEDED(hr))
	{
		long rate = -2;
		pVoice->SetRate(rate);
		hr = pVoice->Speak(wstr.c_str(), 0, NULL);
		pVoice->Release();
		pVoice = NULL;
	}

	::CoUninitialize();
	return TRUE;
}