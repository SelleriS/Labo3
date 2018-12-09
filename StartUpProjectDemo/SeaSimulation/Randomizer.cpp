/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#include "Randomizer.h"


/**
 * Randomizer implementation
 * 
 * Randomizer Class provides methods  to generate random, numbers, types and positions.
 * All its methods and its attributes are static.
 * There should be one randomizer object created in the main file, that way mGenerator is initialized.
 */


Randomizer::Randomizer()
{
	Randomizer::mGenerator = new QRandomGenerator();
}

/**
 * @param min minimum bound
 * @param max maximum bound
 * @return int
 */
int Randomizer::randInt(int min, int max)
{
    return mGenerator->bounded(min, max);
}

/**
 * @return enum
 */
Sex Randomizer::randSex()
{
	int random = randInt(0, 100);
	if (random < 50) 
	{ 
		return Sex::Male; 
	}
	else { 
		return Sex::Female; 
	}
}

/**
 * @param qreal min
 * @param qreal max
 * @return qreal
 */
qreal Randomizer::randQReal(double min, double max)
{
    return (mGenerator->bounded(max-min)) + min;
}

/**
 * @param float min
 * @param float max
 * @return float
 */
float Randomizer::randFloat(double min, double max) {
    return static_cast<float>((mGenerator->bounded(max - min)) + min);
}

LoadType Randomizer::randLoadType()
{
	int random = randInt(0, 100);
	if (random < 50)
	{
		return LoadType::Fish;
	}
	else {
		return LoadType::Fuel;
	}
}

