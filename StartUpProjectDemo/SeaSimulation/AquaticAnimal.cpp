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

AquaticAnimal::AquaticAnimal(FishType type, int energy_level, qreal speed)
	: BasicItem(),
	mFishType(type),
	mEnergyLevel(energy_level),
	mMaxEnergyLevel(100),
	mSpeed(speed), 
	mSex(Randomizer::randSex()),
	mAwarenessRadius(Randomizer::randQReal(5,20)) // awareness radius of a fish is randomly chosen, 
												  // this will influence the fishes ability to survive
{
}

 int AquaticAnimal::energyLevel()
 {
	 return mEnergyLevel;
 }

 qreal AquaticAnimal::speed()
 {
	 return mSpeed;
 }

 qreal AquaticAnimal::awarenessRadius()
 {
	 return mAwarenessRadius;
 }

 Sex AquaticAnimal::sex()
 {
	 return mSex;
 }

 FishType AquaticAnimal::fishType()
 {
	 return mFishType;
 }

 void AquaticAnimal::setEnergyLevel(int newEnergyLevel)
 {
	 mEnergyLevel = newEnergyLevel;
 }

 void AquaticAnimal::setSpeed(int newSpeed)
 {
	 mSpeed = newSpeed;
 }

/**
 * @return void
 */
void AquaticAnimal::advance() {
	return;
}