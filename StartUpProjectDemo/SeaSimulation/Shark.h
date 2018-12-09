/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#ifndef _SHARK_H
#define _SHARK_H

#include "AquaticAnimal.h"


class Shark: public AquaticAnimal {
public: 
void advance() override;

private:
	bool inDanger() override;
};

#endif //_SHARK_H