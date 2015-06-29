#include "Games.h"



void Games::WordGame(vector<string> words, vector<string> definitions, vector<string> pronunciations)
{
	system("cls");
	cout << "Word Game!!" << endl << endl;
	cout << "Try to spell the words I say to you, each word is worth 10 points" << endl << "You lose 2 points for every incorrect attempt" << endl;
	system("PAUSE");
	input = "";

	//set randon number seed
	srand(time(NULL));	

	//resetting values to prevent them from being carried over from other game
	total = 0;
	score = 0;
	numberOfWords = 0;

	//play game till user want to stop
	while (input != "exit")
	{
		system("cls");
		//getting random word
		random = rand() % words.size();

		currentScore = 10;
		numberOfWords += 1;
		cout << endl<< "This is word number: " << numberOfWords << endl;
			//user answering
			while(input != words[random] && currentScore > 0)
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

				cout << "Enter your answer or type 'exit' to finish the game. No capitalization needed." << endl<<endl;
				cin >> input;

				//checking possibilities of user input
				if (input == words[random])
				{
					total += 10;
					score += currentScore;

					cout << endl<< "Correct! Your current total score is: " << score << "out of " << total << endl << "Lets move on to the next word" << endl << endl;
					system("pause");
					break;
					
				}
				else if (input == "exit")
				{
					system("cls");
					cout << endl<< "Game over" << endl << "your score was : " << score << endl << "out of a possible: " << total << endl;
					system("pause");
					system("cls");
					break;
				}
				else
				{
					currentScore += -2;
					if (currentScore == 0)
					{
						cout << endl << "Sorry too many incorrect attempts, the word was : " << words[random] << endl;
						total += 10;
						system("pause");
						break;
					}
					else
					{
						system("cls");
						cout << "Incorrect, pleasse try again" << endl << "Your last attempt was: "<<input<<endl;
					}
				}
			}
		
	}
}
void Games::DefinitionGame(vector<string> words, vector<string> definitions, vector<string> pronunciations)
{
	//resetting values to prevent them from being carried over from other game
	total = 0;
	score = 0;
	numberOfWords = 0;
	input = "";

	system("cls");
	cout << "Definition Game!!" << endl << endl;
	cout << "Try to match each word with the correct definition, each word is worth 6 points" << endl << "You lose 3 points for an incorrect attempt" << endl;
	system("pause");

	//set randon number seed
	srand(time(NULL));

	while (intInput != 0)
	{
		intInput = 10;
		numberOfWords += 1;
		currentScore = 6;

		//location correct definition will appear in answers
		random = rand() % 3;
		random++;

		//getting correct definitions
		correctDef = rand() % definitions.size();

		//getting incorrect definitions
		def1 = rand() % definitions.size();
		def2 = rand() % definitions.size();

		//ensuring they are not the same 
		while (def1 == correctDef || def1 == def2)
			def1 = rand() % definitions.size();

		while (def2 == correctDef || def2 == def1)
			def2 = rand() % definitions.size();

		
		//individual word guessing
		while (intInput != random && currentScore >0)
		{
			
			system("cls");

			//this line will give the answer to every question
			//cout << "answer " << random << endl;


			cout << "Word number: " << numberOfWords << endl;
			cout << "Current possible word score: " << currentScore << endl << endl;
			cout << "Word is: " << words[correctDef] << endl << endl;
			if (random == 1)
			{
				cout << "1) " << definitions[correctDef] << endl;

				//inner ifs are to hide incorrect selections
				if (intInput == 2)
					cout << endl;
				else
					cout << "2) " << definitions[def1] << endl;

				if (intInput == 3)
					cout << endl;
				else
					cout << "3) " << definitions[def2] << endl;
			}
			else if (random == 2)
			{
				if (intInput == 1)
					cout << endl;
				else
					cout << "1) " << definitions[def1] << endl;

				cout << "2) " << definitions[correctDef] << endl;

				if (intInput == 3)
					cout << endl;
				else
					cout << "3) " << definitions[def2] << endl;
			}
			else if (random == 3)
			{
				if (intInput == 1)
					cout << endl;
				else
					cout << "1) " << definitions[def1] << endl;

				if (intInput == 2)
					cout << endl;
				else
					cout << "2) " << definitions[def2] << endl;

				cout << "3) " << definitions[correctDef] << endl;
			}

			cout << endl << "Select the definition of the word by entering the corresponding number or enter '0' to exit" << endl;
			if (cin >> intInput)
			{
				if (intInput < 0 || intInput>3)
				{
					cout << "That is not in the vaild range of answers, try either '1', '2', or '3' "<<endl;

					cin.clear();
					fflush(stdin);

					system("pause");
				}
				else if (intInput == random)
				{
					total += 6;
					score += currentScore;
					cout << "Correct! Your current total score is: " << score << " out of " << total << endl << "Lets move on to the next word" << endl;

					cin.clear();
					fflush(stdin);

					system("pause");
				}
				else if (intInput == 0)
				{
					system("cls");
					cout << endl << "Game over" << endl << "your score was : " << score << endl << "out of a possible: " << total << endl;

					cin.clear();
					fflush(stdin);

					system("pause");
					break;
				}
				else
				{
					currentScore += -3;
					if (currentScore < 1)
					{
						total += 6;
						cout << "Too many attempts, the correct answer was " << endl<< random << ") " << definitions[correctDef] << endl<<endl;
						cout << "lets move on to the next word" << endl;

						cin.clear();
						fflush(stdin);

						system("pause");
						break;
					}
					else
					{
						cout << "Incorrect, please try again" << endl;

						cin.clear();
						fflush(stdin);

						system("pause");
					}
				}
			}
			else
			{
				cout << "not a valid input, please select only one of the 3 possible definitions by enter '1', '2', or '3'" << endl;
				cin.clear();
				fflush(stdin);
				system("pause");
			}

		}
	}
}
