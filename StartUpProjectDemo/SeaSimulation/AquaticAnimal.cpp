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

AquaticAnimal::AquaticAnimal(FishType type, qreal energy_level, qreal speed)
	: BasicItem(),
	mFishType(type),
	mEnergyLevel(energy_level),
	mMaxEnergyLevel(100),
	mSpeed(speed), 
	mSex(Randomizer::randSex()),
	mEnergyDepletion(Randomizer::randQReal(0.01, 0.5)), // This will influence the lifespan of a fish. Some fish will burn more energy than others.
	mAwarenessRadius(Randomizer::randQReal(5,20))	// Awareness radius of a fish is randomly chosen, 
													// this will influence the fishes ability to survive
{
}

 qreal AquaticAnimal::energyLevel()
 {
	 return mEnergyLevel;
 }

 qreal AquaticAnimal::energyDepletion()
 {
	 return mEnergyDepletion;
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

/**
 * Checks if an animal is in danger and returns its biggest threat.
 * This is implemented in the classes RedFish, SwordFish an Shark because they are specific to those classes
 * Every type of fish has different types of threats.
 */
QGraphicsItem* AquaticAnimal::inDanger()
{
	return nullptr;
}

/**
 * returns if an animal has a low energy level.
 * This will be used in the advance method of the specific animal, because it will change its behavior
 */
bool AquaticAnimal::hungry()
{
	return mEnergyLevel < 70; // Fish get hungry when their energylevel is below 70
}

/**
 * This method will check if there are enough fish of the same type around a certain animal so they can form a group
 * This will also be implemented in the child classes
 */
bool AquaticAnimal::groupBFormed()
{
	return false;
}

/**
 *This method will you the awarenessRadius of an animal to scan their surrounding for treaths or other items
 */
QList<QGraphicsItem*> AquaticAnimal::scanSurrounding()
{
	mSurroundingQGItems.clear(); // clears list before every scan
	qreal x = this->x(); // equivalent to this->pos().x()
	qreal y = this->y(); // gets the y coordinate of the position
	QGraphicsScene * scene = this->scene();

	for ((x - mAwarenessRadius); x <= (x + mAwarenessRadius); x += 0.1) // the coordinates are given with floating point precision, so the smallest value is 0.1 
	{
		for ((y - mAwarenessRadius); y <= (y + mAwarenessRadius); y += 0.1 )
		{
			QGraphicsItem * item = scene->itemAt(x, y, QTransform()); // this line wouldn't be possible without including "StartUpProjectDemo.h" because scene is from a incomplete class (not instantiated)	
			if(item) { mSurroundingQGItems.push_back(item); } // Make a list of all the items in the neighbourhood											   
		}
	}
	return mSurroundingQGItems;
}



