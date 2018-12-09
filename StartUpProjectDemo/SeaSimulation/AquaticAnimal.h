/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#ifndef _AQUATICANIMAL_H
#define _AQUATICANIMAL_H

#include "BasicItem.h"
#include "Sex.h"
#include "FishType.h"


class AquaticAnimal : public BasicItem {
public:

	AquaticAnimal(FishType type, int energy_level, qreal speed);

	int getEnergyLevel();
	qreal getSpeed();
	qreal getAwarenessRadius();
	Sex getSex();
	FishType getType();

	void setEnergyLevel(int newEnergyLevel);
	void setSpeed(int newSpeed);

	virtual void advance();

private:
	int mEnergyLevel;
	int mMaxEnergyLevel;
	qreal mSpeed;
	qreal mAwarenessRadius;
	Sex mSex = Male;
	FishType mFishType = RedFish;
};

#endif //_AQUATICANIMAL_H