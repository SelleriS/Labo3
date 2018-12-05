/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#ifndef _EAT_H
#define _EAT_H

#include "Kill.h"


class Eat: public Kill {
public: 
	
void increaseEnergyLevel();
};

#endif //_EAT_H