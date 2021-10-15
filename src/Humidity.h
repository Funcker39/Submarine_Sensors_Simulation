/*
 * Humidity.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Funcker
 */

#ifndef HUMIDTY_H_
#define HUMIDTY_H_

#include "Sensor.h"

class Humidity : public Sensor
{
public:
	virtual ~Humidity();
protected:
	Data aleaGenVal();
};


#endif /* TEMPERATURE_H_ */
