#include "Games.h"



void Games::WordGame(vector<string> words, vector<string> definitions, vector<string> pronunciations)
{
	cout << "Word Game!!" << endl << endl;
	cout << "Try to spell the words I say to you, each word is worth 10 points" << endl << "You lose 2 points for every incorrect attempt" << endl;
	system("PAUSE");

	//set randon number seed
	srand(time(NULL));


	//play game till user want to stop
	while (input != "exit")
	{
		//getting random word
		random = rand() % words.size();

		currentScore = 10;
		numberOfWords += 1;
		cout << endl<< "This is word number: " << numberOfWords << endl;
			//user answering
			while(input != words[random] || currentScore >0)
			{
				cout << "Current possible word score: " << currentScore << endl;

				//speaking word
				if (!talk.say(pronunciations[random]))
				{
					//if text to speech fails game closes
					cout << "Text to speech failed, exiting game ";
					input = "exit";
					break;
				}

				cout << "Enter your answer or type 'exit' to finish the game. No capitalization needed." << endl;;
				cin >> input;

				//checking possibilities of user input
				if (input == words[random])
				{
					total += 10;
					score += currentScore;

					cout << endl<< "Correct! Your current total score is: " << score << "out of " << total << endl << "Lets move on to the next word" << endl << endl;
					break;
					
				}
				else if (currentScore == 0)
				{
					cout << endl<<"Sorry too many incorrect attempts, the word was : " << words[random] << endl;
					total += 10;
					break;
				}
				else if (input == "exit")
				{
					cout << endl<< "Game over" << endl << "your score was : " << score << endl << "out of a possible: " << total << endl;
					cout << "exiting game.." << endl;
					break;
				}
				else
				{
					cout << endl<<"Incorrect, pleasse try again" << endl<<endl;
					currentScore += -2;
				}
			}
		
	}
}
void Games::DefinitionGame(vector<string> words, vector<string> definitions, vector<string> pronunciations)
{

}
