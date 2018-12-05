/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#ifndef _FUELLEAK_H
#define _FUELLEAK_H

#include "BasicItem.h"


class FuelLeak: public BasicItem {
public: 
	
void advance() override;

private: 
	qreal mRadius;
};

#endif //_FUELLEAK_H