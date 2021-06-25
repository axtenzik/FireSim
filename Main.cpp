#include <iostream>
#include <conio.h>
#include "Updater.h"

int main(void)
{
	Updater* updater = new Updater;
	char input;
	updater->showDisplay(0);
	while (true)
	{
		input = _getch();
		if (input == 'x') //seperate if as break function in a switch would just continue code, I want to break away
		{
			break;
		}
		switch (input)
		{
		case 'm': //for opening the menu
			updater->menu();
			break;
		case 'l': //Used for debugging, woulld be left out a final program
			updater->showTrees();
			system("pause");
			break;
		case 't': //Shows the defualt screen of trees
			updater->showDisplay(0);
			break;
		case 's': //Shows the hydration of soil
			updater->showDisplay(1);
			break;
		case 'f': //starts a fire
			updater->startFire();
			updater->showDisplay(0);
			break;
		case '\r': //advances the program
			updater->updateFrame();
			updater->showDisplay(0);
			break;
		}
	}
	system("pause");
}