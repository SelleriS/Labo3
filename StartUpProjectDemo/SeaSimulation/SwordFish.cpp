/**
 * Project SeaSimulation
 * @author A. Francoeur & S. Selleri
 * @version 0.1
 */


#include "SwordFish.h"
#include <math.h>
#include <QtMath>
#include "Randomizer.h"


/**
 * SwordFish implementation
 *
 * SwordFish Class is an implementation of AquaticAnimal representing a swordfish. It can eat other redfish.
 */


 /**
  * This method will determine and set the new position and rotation of the shark depending on its surrounding (danger?)
  * and its state (hungry?)
  * !!! MOVE IN GROUP IS NOT IMPLEMENTED !!!
  */
void SwordFish::advance() 
{
	static constexpr const qreal maxDeviation{ 12.5 }; // in °
	QPointF newPosition;
	qreal newOrientationDegrees;
	QGraphicsItem* threat = this->inDanger();
	if (threat)  // If there is a threat in the surrounding
	{
		// move in the opposite direction with a slight deviation from where the threat is coming from 
		QPointF angle = this->pos() - threat->pos();
		qreal interOrientationDegrees = qAtan(angle.y() / angle.x());
		newOrientationDegrees = interOrientationDegrees + Randomizer::randQReal(-maxDeviation, maxDeviation);
		qreal newOrientationRadians{ qDegreesToRadians(newOrientationDegrees) };
		// calculate new position with the new orientation and speed
		newPosition = pos() + QPointF(qCos(newOrientationRadians), qSin(newOrientationRadians)) * this->speed();
	}
	else if (this->hungry())
	{
		QGraphicsItem* prey = this->searchPrey(); // Look for the closest prey in the surrounding
		if (prey)
		{
			// move towards the closest prey
			QPointF angle = this->pos() - prey->pos();
			newOrientationDegrees = qAtan(angle.y() / angle.x());
			qreal newOrientationRadians{ qDegreesToRadians(newOrientationDegrees) };
			// calculate new position with the new orientation and speed
			newPosition = pos() + QPointF(qCos(newOrientationRadians), qSin(newOrientationRadians)) * this->speed();
		}
		else
		{
			// No prey in the surrounding, shark moves randomly till it finds prey
			newOrientationDegrees = rotation() + Randomizer::randQReal(-maxDeviation, maxDeviation)*8; // *8 => When hungry the swordfish will make bigger rotation changes to find prey 
			qreal newOrientationRadians{ qDegreesToRadians(newOrientationDegrees) };
			newPosition = pos() + QPointF(qCos(newOrientationRadians), qSin(newOrientationRadians)) * this->speed();
		}
	}
	else
	{
		// If the shark is not in danger or it is not hungry it will move around randomly
		newOrientationDegrees = rotation() + Randomizer::randQReal(-maxDeviation, maxDeviation);
		qreal newOrientationRadians{ qDegreesToRadians(newOrientationDegrees) };
		newPosition = pos() + QPointF(qCos(newOrientationRadians), qSin(newOrientationRadians)) * this->speed();
	}

	setRotation(newOrientationDegrees);
	setPos(newPosition);
	setEnergyLevel(energyLevel() - energyDepletion()); // Every move will deplete a certain amount of energy
}

QGraphicsItem * SwordFish::inDanger()
 {
	QGraphicsItem* biggestThreat{ nullptr };
	qreal distanceBT{ this->awarenessRadius() + 1 }; //initializing the distance to the biggest threat to one over the maximum it can be. That way every new threat is closer.
	QList<QGraphicsItem*> contacts = scanSurrounding();
	QList<QGraphicsItem*>::const_iterator i;
	for (i = contacts.constBegin(); i != contacts.constEnd(); ++i)
	{
		QGraphicsItem* newThreat = *i;
		std::string name = typeid(newThreat).name();

		if (!name.compare("class FuelLeak") || this->type() == newThreat->type()) // SworsFish has two threats, fuelleaks and fuelleaks
		{
			if (biggestThreat)
			{
				// Calculate distance between the new threat and the swordfish
				qreal distancexNT = (this->x() - newThreat->x());
				qreal distanceyNT = (this->y() - newThreat->y());
				qreal distanceNT = pow((pow(distancexNT, 2) + pow(distanceyNT, 2)), 0.5);

				if (distanceNT < distanceBT) // The biggest threat is the threat that is the closest
				{ 
					biggestThreat = newThreat; 
					distanceBT = distanceNT;
				} 
			}
			else 
			{ 
				biggestThreat = newThreat; 
				// Calculate distance between the current biggest threat and the swordfish
				qreal distancexBT = (this->x() - biggestThreat->x());
				qreal distanceyBT = (this->y() - biggestThreat->y());
				qreal distanceBT = pow((pow(distancexBT, 2) + pow(distanceyBT, 2)), 0.5);
			}
		}
	}

	return biggestThreat;
 }

// NOT IMPLEMENTED
 bool SwordFish::groupBFormed()
 {
	 return false;
 }

 QGraphicsItem * SwordFish::searchPrey()
 {
	 QGraphicsItem* closestPrey{ nullptr };
	 qreal distanceCP;
	 QList<QGraphicsItem*> contacts = scanSurrounding();
	 QList<QGraphicsItem*>::const_iterator i;
	 for (i = contacts.constBegin(); i != contacts.constEnd(); ++i)
	 {
		 QGraphicsItem* newPrey = *i;
		 if (newPrey->type() == FishType::RedFish) // RedFishes prey for swordfishes
		 {
			 if (closestPrey)
			 {
				 // Calculate distance between the new prey and the swordfish
				 qreal distancexNP = (this->x() - newPrey->x());
				 qreal distanceyNP = (this->y() - newPrey->y());
				 qreal distanceNP = pow((pow(distancexNP, 2) + pow(distanceyNP, 2)), 0.5);

				 if (distanceNP < distanceCP)
				 {
					 closestPrey = newPrey;
					 distanceCP = distanceNP;
				 }
			 }
			 else
			 {
				 closestPrey = newPrey;
				 // Calculate distance between the current closest prey and the swordfish
				 qreal distancexCP = (this->x() - closestPrey->x());
				 qreal distanceyCP = (this->y() - closestPrey->y());
				 distanceCP = pow((pow(distancexCP, 2) + pow(distanceyCP, 2)), 0.5);
			 }
		 }
	 }
	 return closestPrey;
 }
