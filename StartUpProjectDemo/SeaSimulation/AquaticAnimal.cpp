/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#include "AquaticAnimal.h"
#include "Randomizer.h"

 /**
   * AquaticAnimal implementation
   *
   * AquaticAnimal Class is an abstract representation of an aquatic animal.  AquaticAnimal is killed when a collision occurs with a Boat or FuelLeak.
   */


AquaticAnimal::AquaticAnimal(int energy_level, qreal speed)
	: BasicItem()
mEnergyLevel(energy_level),
	mMaxEnergyLevel(100),
	mSpeed(speed), mSex(Randomizer::randSex())
{
}

/**
 * @return void
 */
void AquaticAnimal::advance() {
	return;
}