#ifndef Updater_h
#define Updater_h
#include "Tree.h"
#include "Grid.h"
#include "Weather.h"

class Updater
{
private:
	TreeList* forest;

	/// <summary>
	/// Land trees are on
	/// </summary>
	Grid* land;

	/// <summary>
	/// for wetness
	/// </summary>
	Grid* soil;
	Weather* weather;
	bool firstFire; //bool to see if a fire has been set before, first fire set is always in the centre
public:
	/// <summary>
	/// constructor
	/// </summary>
	Updater();

	/// <summary>
	/// sets up the 2 grids and all the trees 
	/// </summary>
	void populate();

	/// <summary>
	/// starts a fire
	/// </summary>
	void startFire();

	/// <summary>
	/// make ground wetter
	/// </summary>
	void rain();

	/// <summary>
	/// updates the program to the next frame
	/// </summary>
	void updateFrame();

	/// <summary>
	/// Updates all the trees
	/// </summary>
	void updateTrees();

	/// <summary>
	/// updates the grids
	/// </summary>
	void updateGrid();

	/// <summary>
	/// shows the default display
	/// </summary>
	/// <param name="selector">chooses whether to show trees or soil</param>
	void showDisplay(int selector);

	/// <summary>
	/// Gets list of all trees
	/// </summary>
	void showTrees();

	/// <summary>
	/// shows the menu for the user
	/// </summary>
	void menu();
};

#endif // !"Updater_h"