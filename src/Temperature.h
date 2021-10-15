/*
 * Temperature.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Funcker
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#include "Sensor.h"

class Temperature : public Sensor
{
public:
	virtual ~Temperature();
protected:
	Data aleaGenVal();
};


#endif /* TEMPERATURE_H_ */
