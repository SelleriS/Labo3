/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#ifndef _BOAT_H
#define _BOAT_H

#include "BasicItem.h"
#include "LoadType.h"


class Boat: public BasicItem {
public: 
	
virtual void advance() = 0;

private: 
	int mLoad;
	int mMaxLoad;
	qreal mSpeed;
	qreal mManuverability;
	LoadType mLoadType;
	
virtual void updateSpeed() = 0;
	
virtual void updateLoad() = 0;
};

#endif //_BOAT_H