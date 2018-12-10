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
#include "qlist.h"


class AquaticAnimal : public BasicItem {
public:

	AquaticAnimal(FishType type, qreal energy_level, qreal speed);

	qreal energyLevel();
	qreal energyDepletion();
	qreal speed();
	qreal awarenessRadius();
	Sex sex();
	FishType fishType();

	void setEnergyLevel(int newEnergyLevel);
	void setSpeed(int newSpeed);

	virtual void advance();

private:
	qreal mEnergyLevel;
	qreal mMaxEnergyLevel;
	const qreal mEnergyDepletion;
	qreal mSpeed;
	qreal mAwarenessRadius;
	Sex mSex = Male;
	FishType mFishType = RedFish;
	QList<QGraphicsItem*> mSurroundingQGItems;

protected:
	virtual QGraphicsItem* inDanger();
	virtual bool groupBFormed();
	bool hungry();
	QList<QGraphicsItem*> scanSurrounding();
};

#endif //_AQUATICANIMAL_H