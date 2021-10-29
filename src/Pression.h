/*
 * Pression.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Funcker
 */

#ifndef PRESSION_H_
#define PRESSION_H_

#include "Sensor.h"
#include <math.h>

/*
 * Pression class :
 * Class inheriting the Sensor superclass, using integer data type.
 */
class Pression : public Sensor<int>
{
public:
	Pression();
	virtual ~Pression();
protected:
	void aleaGenVal();
};




#endif /* PRESSION_H_ */
