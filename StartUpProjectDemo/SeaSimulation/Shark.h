/**
 * Project SeaSimulation
 * @author A. Francoeur & S. Selleri
 * @version 0.1
 */


#ifndef _SHARK_H
#define _SHARK_H

#include "AquaticAnimal.h"


class Shark: public AquaticAnimal {
public: 
void advance() override;

private:
	QGraphicsItem* inDanger() override;
	bool groupBFormed() override;
	QGraphicsItem* searchPrey();
};

#endif //_SHARK_H