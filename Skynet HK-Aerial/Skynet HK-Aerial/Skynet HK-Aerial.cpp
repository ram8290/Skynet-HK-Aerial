// Skynet HK-Aerial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int enemyPlacement = rand() % 64 + 1;
	int tries = 1;
	int searchGridHighNumber = 64;
	int searchGridLowNumber = 1;
	int guess = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

	cout << "Generate Ramdom enemy location on 8x8 grid....\n";
	cout << "The enemy is located at location #" << enemyPlacement << " on 8x8 grid with 1-64 sectors.\n";
	cout << "Skynet HK-Aerial Initializing software.....\n";
	cout << "=================================================================\n";
	do
	{
		if (guess < enemyPlacement)
		{
			cout << "Skynet HK-Aerial Radar sending out ping #" << tries << "\n";
			cout << " The target location prediction of " << guess << " was lower than the actual enemy location of " << enemyPlacement << ".\n";
			cout << "The new searchGridLowNumber =" << guess + 1 << ".\n";
			cout << "=================================================================\n";
			searchGridLowNumber = ++guess;
			++tries;
			guess = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		}
		else if (guess > enemyPlacement)
		{
			cout << "Skynet HK-Aerial Radar sending out ping #" << tries << "\n";
			cout << " The target location prediction of " << guess << " was higher than the actual enemy location of " << enemyPlacement << ".\n";
			cout << "The new searchGridHighNumber =" << --guess << ".\n";
			cout << "=================================================================\n";
			searchGridHighNumber = --guess;
			++tries;
			guess = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		}
		
	} while (guess != enemyPlacement);
	
	
	cout << "Skynet HK-Aerial Radar sending out ping #" << tries << "\n";
	cout << "Enemy was hiding at location #" << enemyPlacement << ".\n";
	cout << "Target was found at location #" << guess << ".\n";
	cout << "skynet HK-Aerial Software took " << tries << " predictions to find the enemy location on a grid size of 8x8 (64).\n";
	
	return 0;
}
