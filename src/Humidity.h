/*
 * Humidity.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Funcker
 */

#ifndef HUMIDTY_H_
#define HUMIDTY_H_

#include "Sensor.h"

/*
 * Humidity class :
 * Class inheriting the Sensor superclass, using float data type.
 */
class Humidity : public Sensor<float>
{
public:
	Humidity();
	virtual ~Humidity();
protected:
	void aleaGenVal();
};


#endif /* TEMPERATURE_H_ */
