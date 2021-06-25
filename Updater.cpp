#include <iostream>
#include "Updater.h"

Updater::Updater()
{
	forest = new TreeList;
	land = new Grid;
	soil = new Grid;
	weather = new Weather;
	firstFire = false;
	populate();
	srand(time(0)); //sets seed for rand()
}

void Updater::populate()
{
	for (int y = 1; y < 20; y++) //starts at 1 and ends at 20 to keep perimeter of 1 plot around edge
	{
		for (int x = 1; x < 20; x++)
		{
			forest->addTree(x, y);
			land->setChar(x, y, 'T'); //sets so tree is alive and not on fire
			soil->setChar(x, y, '.'); //sets so soil is dry
		}
	}
}

void Updater::startFire()
{
	if (!forest->isEmpty()) //if not empty
	{
		TreeNode* current = forest->getStart();
		int x = rand() % 20 + 1; //makes random x value
		int y = rand() % 20 + 1; //makes random y value
		
		//only for first fire, all afterwards is random
		//sets fire to tree and update land
		if (land->getChar(10, 10) == 'T' && firstFire == false) //could have just first fire = false but this way I know a tree is being set on fire and not fire or ground
		{
			while (current != NULL) //loops till current is null
			{
				if (current->getTree()->getX() == 10 && current->getTree()->getY() == 10) //loops till current is the desired tree
				{
					current->getTree()->setStatus(2); //status 2 is on fire
					land->setChar(10, 10, '#'); //# is on fire
					break; //break out of while loop
				}

				current = current->getNext();
			}
			firstFire = true;
		}
		else if (land->getChar(x, y) == 'T') //checks to see if random coordinate is a tree, afterwards is just same as above
		{
			while (current != NULL)
			{
				if (current->getTree()->getX() == x && current->getTree()->getY() == y) //loops till current is the desired tree
				{
					current->getTree()->setStatus(2);
					land->setChar(x, y, '#');
					break;
				}

				current = current->getNext();
			}
		}
	}
}

void Updater::rain()
{
	for (int y = 1; y < 20; y++)
	{
		for (int x = 1; x < 20; x++)
		{
			char current = soil->getChar(x, y);

			//checks two soil levels that can be increased and increases them
			if (current == '.')
			{
				soil->setChar(x, y, 'o');
			}
			else if (current == 'o')
			{
				soil->setChar(x, y, '@');
			}
		}
	}
}

void Updater::updateTrees()
{
	TreeNode* current;
	current = forest->getStart();
	while (current != NULL)
	{
		//update tree
		int xpos = current->getTree()->getX();
		int ypos = current->getTree()->getY();
		int rnd = rand() % 100 + 1;
		int chance = 0;

		if (land->getChar(xpos, ypos) == 'T') // See if tree will set fire
		{
			//each if is an adjacent tree (or border)
			if (land->getChar(xpos - 1, ypos) == '#')
			{
				chance = chance + 40 + weather->getWindX();
			}
			if (land->getChar(xpos + 1, ypos) == '#')
			{
				chance = chance + 40 - weather->getWindX();
			}
			if (land->getChar(xpos, ypos - 1) == '#')
			{
				chance = chance + 40 + weather->getWindY();
			}
			if (land->getChar(xpos, ypos + 1) == '#')
			{
				chance = chance + 40 - weather->getWindY();
			}

			if (rnd <= chance) //if rnd is less than chance set tree to be on fire
			{
				current->getTree()->setStatus(2);
			}
			else // if tree is not set on fire update trees hydration
			{
				if (current->getTree()->getHydration() < 2) 
				{
					if (soil->getChar(xpos, ypos) == '@' && 10 > rand() % 100) // 10% chance of hydration on wet soil
					{
						current->getTree()->setHydration(current->getTree()->getHydration() + 1);
						soil->setChar(xpos, ypos, 'o'); //reduce soil wetness level
					}
					else if ((soil->getChar(xpos, ypos) == 'o' && 5 > rand() % 100)) // 5% chance of hydration on moist soil
					{
						current->getTree()->setHydration(current->getTree()->getHydration() + 1);
						soil->setChar(xpos, ypos, '.');
					}
				}
				if (current->getTree()->getHydration() > 0 && 10 > rand() % 100) //10 chance of using current hydration
				{
					current->getTree()->setHydration(current->getTree()->getHydration() - 1);
				}
			}
		}
		else if (land->getChar(xpos, ypos) == '-') // See if tree will grow in empty soil
		{
			if (soil->getChar(xpos, ypos) == '@')
			{
				if (3 > rand() % 100) // 3% chance to grow on fully wet soil
				{
					land->setChar(xpos, ypos, 'T');
					current->getTree()->setStatus(1);
					current->getTree()->setHydration(0);
					soil->setChar(xpos, ypos, '.');
				}
			}
			else if (soil->getChar(xpos, ypos) == 'o')
			{
				if (1 > rand() % 100) // 1% chance to grow on half wet soil
				{
					land->setChar(xpos, ypos, 'T');
					current->getTree()->setStatus(1);
					current->getTree()->setHydration(0);
					soil->setChar(xpos, ypos, '.');
				}
			}
		}
		else if (land->getChar(xpos, ypos) == '#') // See if tree burns down
		{
			if (current->getTree()->getHydration() <= 0)
			{
				current->getTree()->setStatus(0);
				soil->setChar(xpos, ypos, '.');
			}
			else
			{
				current->getTree()->setHydration(current->getTree()->getHydration() - 1);
			}
		}

		current = current->getNext();
	}
}

void Updater::updateGrid()
{
	TreeNode* current;
	current = forest->getStart();
	while (current != NULL)
	{
		//get trees coordinates
		int xpos = current->getTree()->getX();
		int ypos = current->getTree()->getY();

		if (current->getTree()->getStatus() == 1) //if a tree is alive and not on fire
		{
			land->setChar(xpos, ypos, 'T');
		}
		else if (current->getTree()->getStatus() == 2) //if a tree is on fire
		{
			land->setChar(xpos, ypos, '#');
		}
		else
		{
			land->setChar(xpos, ypos, '-');
		}

		current = current->getNext();
	}
}

void Updater::updateFrame()
{
	if (!forest->isEmpty())
	{
		if (weather->getRainChance() >= 20)
		{
			rain();
			weather->resetRainChance();
		}
		updateTrees(); //update each tree, chance to set on fire if neighbors are on fire
		updateGrid(); //update land so each tree is correctly displayed
		//all trees need status updated BEFORE the grid so fire doesn't spread or die out too soon
		weather->weatherChange(); //update weather
	}
}

void Updater::showDisplay(int selector)
{
	system("cls");
	Grid* toDisplay;
	if (selector == 0) //choose what grid to display
	{
		toDisplay = land;
	}
	else if (selector == 1)
	{
		toDisplay = soil;
	}
	else // just in case
	{
		toDisplay = land;
	}
	for (int y = 0; y < 21; y++) //creates the display
	{
		for (int x = 0; x < 21; x++)
		{
			if (x == 20)
			{
				std::cout << toDisplay->getChar(x, y) << std::endl;
			}
			else
			{
				std::cout << toDisplay->getChar(x, y) << " ";
			}
		}
	}
	std::cout << "wind speed is currently: " << weather->getWindX() << " on the x axis" << std::endl;
	std::cout << "and " << weather->getWindY() << " on the y axis" << std::endl << std::endl;
	std::cout << "Press m to bring up menu or" << std::endl;
	std::cout << "Press enter to continue ";
}

void Updater::showTrees()
{
	system("cls");
	forest->listAll();
}

void Updater::menu()
{
	system("cls");
	std::cout << "List of options:" << std::endl;
	std::cout << "m - Menu button" << std::endl;
	std::cout << "s - Show hydration of soil" << std::endl;
	std::cout << "t - Show trees" << std::endl;
	std::cout << "f - chance to start fire" << std::endl;
	std::cout << "x - close program" << std::endl;
	std::cout << "Enter key - for progressing program" << std::endl << std::endl;
}