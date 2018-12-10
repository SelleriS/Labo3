/**
 * Project SeaSimulation
 * @author A. Francoeur & S. Selleri
 * @version 0.1
 */


#ifndef _SWORDFISH_H
#define _SWORDFISH_H

#include "AquaticAnimal.h"


class SwordFish: public AquaticAnimal {
public: 
	
void advance() override;

private:
	QGraphicsItem* inDanger() override;
	bool groupBFormed() override;
	QGraphicsItem* searchPrey();
};

#endif //_SWORDFISH_H