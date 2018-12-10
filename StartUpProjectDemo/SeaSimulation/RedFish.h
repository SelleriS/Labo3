/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#ifndef _REDFISH_H
#define _REDFISH_H

#include "AquaticAnimal.h"


class RedFish: public AquaticAnimal {
public: 
	
void advance() override;

private:
	QGraphicsItem* inDanger() override;
	bool groupBFormed() override;
};

#endif //_REDFISH_H