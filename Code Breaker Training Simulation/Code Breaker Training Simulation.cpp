// Code Breaker Training Simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Jeff O'Hara
CIA code breaker assigment program
Introduction to Vectors
*/


#include <iostream>
#include <windows.h>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
//Functions
void intro();


int main()
{
	intro();//call intro function for program

	//Display an overview of what Keywords II is to the recruit 
	//Display directions to the recruit on how to use Keywords
	cout << "Please enter letters." << endl;
	cout << "This will help decide if you're CIA material." << endl;

	//Create a collection of 10 words you had written down manually
	//Enter these words using the pushback function into a vector
	vector<string> words;
	words.push_back("covert");
	words.push_back("undercover");
	words.push_back("mole");
	words.push_back("espionage");
	words.push_back("obscurity");
	words.push_back("spiery");
	words.push_back("fodder");
	words.push_back("agent");
	words.push_back("danger");
	words.push_back("worm");

	//Create an int var to count the number of simulations being run starting at 1
	//int numOfSim = 1;

	//Display the simulation # is starting to the recruit.
	//Pick 3 new random words from your collection as the secret code word the recruit has to guess. 
	//Randomize the list
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	char again = 'y';
	int simulations = 0;
	do {
		//for (int i = 0; i < 3; i++)
		//{
			//int i = 0;
			string currentWord = words[i];
			const int MAX_WRONG = 8;  //max number of incorrect tries
			int wrong = 0;
			string soFar(currentWord.size(), '-');
			string used = "";
			//cout << currentWord;
			// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
			while ((wrong < MAX_WRONG) && (soFar != currentWord))
			{
				//Tell recruit how many incorrect guesses he or she has left
				cout << "\n\nYou have " << (MAX_WRONG - wrong);
				cout << " incorrect guesses left.\n";
				//Show recruit the letters he or she has guessed
				cout << "\nYou've used the following letters:\n" << used << endl;
				//Show player how much of the secret word he or she has guessed
				cout << "\nSo far, the word is:\n" << soFar << endl;
				char guess;
				cout << "\n\nEnter your guess: ";
				cin >> guess;
				guess = tolower(guess);
				//While recruit has entered a letter that he or she has already guessed
				//Get recruit ’s guess
				while (used.find(guess) != string::npos)
				{
					cout << "\nYou've already guessed " << guess << endl;
					cout << "Enter your guess: ";
					cin >> guess;
					guess = tolower(guess);
				}
				//     Add the new guess to the group of used letters
				used += guess;
				//     If the guess is in the secret word

				//          Tell the recruit the guess is correct
				if (currentWord.find(guess) != string::npos)
				{
					cout << "That's right! " << guess << " is in the word.\n";
					//          Update the word guessed so far with the new letter
					for (unsigned int i = 0; i < currentWord.length(); ++i)
					{
						if (currentWord[i] == guess)
						{
							soFar[i] = guess;
						}
					}
				}
				//Otherwise,
				//Tell the recruit the guess is incorrect
				//Increment the number of incorrect guesses the recruit has made
				else
				{
					cout << "Sorry, " << guess << " isn't in the word.\n";
					++wrong;
				}
				// If the recruit has made too many incorrect guesses
				//Tell the recruit that he or she has failed the Keywords II course.
				// Otherwise
				//Congratulate the recruit on guessing the secret words
				if (wrong == MAX_WRONG)
					cout << "\nYou've not CIA material!";
				else
					cout << "\nYou are a CIA codebreaker!";
			}
		//}
		//Get recruit's next guess

		cout << "Do you want to try again? (y or n)" << endl;
		cin >> again;
		simulations++;
		cout << "You have run " << simulations << " simulations." << endl;
	} while (again == 'y');
	// Ask the recruit if they would like to run the simulation again
	// If the recruit wants to run the simulation again
	//Increment the number of simulations ran counter		
	//Move program execution back up to // Display the simulation # is starting to the recruit. 
	// Otherwise 
	//Display End of Simulations to the recruit
	cout << "You've reached the end of the program!" << endl;
	//     Pause the Simulation with press any key to continue
	system("pause");
}

//Functions
void intro()
{
	//Display Title of the program to the user
	cout << "Welcome to the CIA Code Breaker Program.\n" << endl;
	//Ask the recruit to log in using their name
	//Hold the recruit's name in a var, and address them by it throughout the simulation.
	string userName;
	cout << "Please login using your name: " << endl;
	cin >> userName;
}