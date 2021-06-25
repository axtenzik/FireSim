#include <iostream>
#include "Weather.h"

Weather::Weather()
{
	windX = 0;
	windY = 0;
	srand(time(0));
	rainChance = 0;
}

void Weather::weatherChange()
{
	rainChance = rainChance + rand() % 3; //increases chance of rain by 0 - 3
	
	//changes both winds x and y, can change by -5 to +5 units
	int xChange = rand() % 11 + (-5);
	int yChange = rand() % 11 + (-5);
	
	if (windX + xChange >= 20) //if wind will end up faster than 20
	{
		windX = 20; //set wind to 20
	}
	else if (windX + xChange <= -20) //same as above but -20
	{
		windX = -20;
	}
	else
	{
		windX = windX + xChange;
	}

	if (windY + yChange >= 20) //same as above but on y axis
	{
		windY = 20;
	}
	else if (windY + yChange <= -20)
	{
		windY = -20;
	}
	else
	{
		windY = windY + yChange;
	}
}

int Weather::getWindX()
{
	return windX;
}

int Weather::getWindY()
{
	return windY;
}

void Weather::resetRainChance()
{
	rainChance = 0;
}

int Weather::getRainChance()
{
	return rainChance;
}