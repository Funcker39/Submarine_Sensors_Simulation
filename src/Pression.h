/*
 * Pression.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Funcker
 */

#ifndef PRESSION_H_
#define PRESSION_H_

#include "Sensor.h"

class Pression : public Sensor
{
public:
	virtual ~Pression();
protected:
	Data aleaGenVal();
};


#endif /* PRESSION_H_ */
