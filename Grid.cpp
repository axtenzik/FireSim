#include "Grid.h"

Grid::Grid()
{
	//Loops though all available x and y coordinates and sets to -
	for (int y = 0; y < 21; y++)
	{
		for (int x = 0; x < 21; x++)
		{
			plot[x][y] = '-';
		}
	}
}

char Grid::getChar(int x, int y)
{
	return plot[x][y];
}

void Grid::setChar(int x, int y, char letter)
{
	plot[x][y] = letter;
}