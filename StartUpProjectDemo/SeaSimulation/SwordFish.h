/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#ifndef _SWORDFISH_H
#define _SWORDFISH_H

#include "AquaticAnimal.h"


class SwordFish: public AquaticAnimal {
public: 
	
void advance() override;

private:
	bool inDanger() override;
	bool groupBFormed() override;
};

#endif //_SWORDFISH_H