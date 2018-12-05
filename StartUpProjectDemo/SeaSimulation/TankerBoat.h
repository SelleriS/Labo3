/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#ifndef _TANKERBOAT_H
#define _TANKERBOAT_H

#include "Boat.h"


class TankerBoat: public Boat {
public: 
	
void advance() override;

private: 
	qreal mHullIntegrity;
	
bool isLeaking();
	
void updateSpeed() override;
	
void updateLoad() override;
	
/**
 * @param qreal
 */
void setHullIntegrity(qreal hIntegrity);
};

#endif //_TANKERBOAT_H