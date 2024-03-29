// Skynet HK-Aerial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//makes sure each time the code is run the random number is different. 
	srand(static_cast<unsigned int>(time(0)));
	// chooses a random number for the enemys posiiton.
	int enemyPlacement = rand() % 64 + 1;
	// keeps track on how many tries it took to find the enemy.
	int tries = 1;
	//starting high number.
	int searchGridHighNumber = 64;
	//starting low number.
	int searchGridLowNumber = 1;
	//calculates a guess to where the enemy is.
	int guess = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
	//displays the start of the program and where the enemy is.
	cout << "Generate Ramdom enemy location on 8x8 grid....\n";
	cout << "The enemy is located at location #" << enemyPlacement << " on 8x8 grid with 1-64 sectors.\n";
	cout << "Skynet HK-Aerial Initializing software.....\n";
	cout << "=================================================================\n";
	do
	{
		//checks if guess is lower.
		if (guess < enemyPlacement)
		{
			cout << "Skynet HK-Aerial Radar sending out ping #" << tries << "\n";
			cout << " The target location prediction of " << guess << " was lower than the actual enemy location of " << enemyPlacement << ".\n";
			cout << "The new searchGridLowNumber =" << guess + 1 << ".\n";
			cout << "=================================================================\n";
			//changes the low number to shorten the gap.
			searchGridLowNumber = ++guess;
			//adds to tries to find out how many tries it took.
			++tries;
			//reruns guess with new values.
			guess = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		}
		//checks if guess is higher.
		else if (guess > enemyPlacement)
		{
			cout << "Skynet HK-Aerial Radar sending out ping #" << tries << "\n";
			cout << " The target location prediction of " << guess << " was higher than the actual enemy location of " << enemyPlacement << ".\n";
			cout << "The new searchGridHighNumber =" << --guess << ".\n";
			cout << "=================================================================\n";
			//changes the high number to shorten the gap.
			searchGridHighNumber = --guess;
			//adds to tries to find out how many tries it took.
			++tries;
			//reruns guess with new values.
			guess = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		}
	  //checks if its not equal then it repeats.	
	} while (guess != enemyPlacement);
	
	//displays results.
	cout << "Skynet HK-Aerial Radar sending out ping #" << tries << "\n";
	cout << "Enemy was hiding at location #" << enemyPlacement << ".\n";
	cout << "Target was found at location #" << guess << ".\n";
	cout << "skynet HK-Aerial Software took " << tries << " predictions to find the enemy location on a grid size of 8x8 (64).\n";
	
	return 0;
}
