/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#ifndef _REPRODUCTION_H
#define _REPRODUCTION_H

class Reproduction {
public: 
	
AquaticAnimal reproduce();
private: 
	
bool isSameType();
	
bool isOppositeSex();
	
void decreaseEnergyLevel();
};

#endif //_REPRODUCTION_H