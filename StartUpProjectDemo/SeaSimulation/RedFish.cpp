/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#include "RedFish.h"

/**
 * RedFish implementation
 * 
 * RedFish Class. RedFish can't eat as it's the lower item in the food chain. This item is deleted if there's a collision with a type other than it's own  or when its age as reached its longevity.
 */


/**
 * @return void
 */
void RedFish::advance() {
    //return;
}

bool RedFish::inDanger()
{
	// Implement danger search
	return false;
}

bool RedFish::groupBFormed()
{
	return false;
}
