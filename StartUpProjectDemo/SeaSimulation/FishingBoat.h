/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#ifndef _FISHINGBOAT_H
#define _FISHINGBOAT_H

#include "Boat.h"


class FishingBoat: public Boat {
public: 
	
void advance() override;

private: 
	QPointF mFishingAreaOrigin;
	qreal mFishingAreaRadius;
	
void updateLoad() override;
	
void updateSpeed() override;
};

#endif //_FISHINGBOAT_H