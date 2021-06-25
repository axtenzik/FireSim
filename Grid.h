#ifndef Grid_h
#define Grid_h

/// <summary>
/// class 2d array grids of 21 by 21
/// </summary>
class Grid
{
private:
	char plot[21][21];
public:
	/// <summary>
	/// constructor
	/// </summary>
	Grid();

	/// <summary>
	/// get the char at specified coordinates
	/// </summary>
	/// <param name="x">x coordinate</param>
	/// <param name="y">y coordinate</param>
	/// <returns></returns>
	char getChar(int x, int y);

	/// <summary>
	/// sets the char at specified coordinate
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="letter">char to be set</param>
	void setChar(int x, int y, char letter);
};

#endif // !Grid_h

