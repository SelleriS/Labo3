/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#ifndef _AQUATICANIMAL_H
#define _AQUATICANIMAL_H

#include "BasicItem.h"
#include "Sex.h"


class AquaticAnimal : public BasicItem {
public:

	AquaticAnimal(int energy_level, qreal speed);

	virtual void advance() = 0;

private:
	int mEnergyLevel;
	int mMaxEnergyLevel;
	qreal mSpeed;
	Sex mSex = Male;
};

#endif //_AQUATICANIMAL_H