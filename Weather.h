#ifndef Weather_h
#define Weather_h

class Weather
{
private:
	int windX;
	int windY;
	int rainChance;
public:
	/// <summary>
	/// constructor
	/// </summary>
	Weather();

	/// <summary>
	/// updates the weather
	/// </summary>
	void weatherChange();

	/// <summary>
	/// gets the winds x speed
	/// </summary>
	/// <returns></returns>
	int getWindX();

	/// <summary>
	/// gets the winds y speed
	/// </summary>
	/// <returns></returns>
	int getWindY();

	/// <summary>
	/// brings rain chance back to 0
	/// </summary>
	void resetRainChance();

	/// <summary>
	/// gets the current chance of rain
	/// </summary>
	/// <returns></returns>
	int getRainChance();
};

#endif // !Weather_h