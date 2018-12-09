/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#ifndef _EAT_H
#define _EAT_H

#include "AquaticAnimal.h"
#include "Kill.h"


class Eat{
public: 
	Eat();
	void increaseEnergyLevel(AquaticAnimal * predator, AquaticAnimal * prey);
};

#endif //_EAT_H