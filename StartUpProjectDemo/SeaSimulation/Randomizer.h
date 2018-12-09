/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#ifndef _RANDOMIZER_H
#define _RANDOMIZER_H
#include <QPoint>
#include <QRandomGenerator>
#include "Sex.h"
#include "LoadType.h"

class Randomizer {
public:

	Randomizer();

	/**
	 * @param min minimum bound
	 * @param max maximum bound
	 */
	static int randInt(int min, int max);

	static Sex randSex();

	/**
	 * @param min
	 * @param max
	 */
	static qreal randQReal(double min, double max);

	/**
	 * @param float min
	 * @param float max
	 */
	static float randFloat(double min, double max);

	static LoadType randLoadType();

private:
	static QRandomGenerator * mGenerator;
};

#endif //_RANDOMIZER_H