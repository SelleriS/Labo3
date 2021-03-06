/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#include "RedFish.h"
#include <math.h>
#include <QtMath>
#include "Randomizer.h"


/**
 * RedFish implementation
 * 
 * RedFish Class. RedFish can't eat as it's the lower item in the food chain. This item is deleted 
 * if there's a collision with a type other than it's own  or when its age as reached its longevity.
 */


/**
   * This method will determine and set the new position and rotation of the shark depending on its surrounding (danger?)
   * !!! MOVE IN GROUP IS NOT IMPLEMENTED !!!
   */
void RedFish::advance() {
	static constexpr const qreal maxDeviation{ 90 }; // in �
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

QGraphicsItem* RedFish::inDanger()
{
	QGraphicsItem* biggestThreat{ nullptr };
	qreal distanceBT{ this->awarenessRadius() + 1}; //initializing the distance to the biggest threat to one over the maximum it can be. That way every new threat is closer.
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

bool RedFish::groupBFormed()
{
	return false;
}
