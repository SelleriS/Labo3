/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#include "Eat.h"

/**
 * Eat implementation
 * 
 * Eat Class .
 */


Eat::Eat()
{
}

/**
 * if energy level of food is higher than 50 it adds 10 energy points otherwise it adds 5 energy points to the predator
 */
void Eat::increaseEnergyLevel(AquaticAnimal * predator, AquaticAnimal * prey) 
{
	int energyExtra{ 0 };
	int newEnergy{ predator->energyLevel()};
	if (prey->energyLevel() > 50) 
	{
		energyExtra = 10;
	}
	else { energyExtra = 5; }

	newEnergy += energyExtra;
	newEnergy = newEnergy > 100 ? 100 : newEnergy; // control to not exceed an energy level higher than 100
	predator->setEnergyLevel(newEnergy);
	Kill newKill = Kill();
    newKill.deleteBasicItem(prey);
}