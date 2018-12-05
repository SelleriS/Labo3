/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#include "TankerBoat.h"

/**
 * TankerBoat implementation
 * 
 * TankerBoat Class is chid of Boat Class,  this object can generate FuelLeak objects.
 */


/**
 * @return void
 */
void TankerBoat::advance() {

}

/**
 * @return bool
 */
bool TankerBoat::isLeaking() {
    return false;
}

/**
 * @return void
 */
void TankerBoat::updateSpeed() {
   
}

/**
 * @return void
 */
void TankerBoat::updateLoad() {
   
}

/**
 * @param qreal
 * @return void
 */
void TankerBoat::setHullIntegrity(qreal hIntegrity) {
	mHullIntegrity = hIntegrity;
}