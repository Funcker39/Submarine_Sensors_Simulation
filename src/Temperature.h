/*
 * Temperature.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Funcker
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#include "Sensor.h"

/*
 * Temperature class :
 * Class inheriting the Sensor superclass, using float data type.
 */
class Temperature : public Sensor<float>
{
public:
	Temperature();
	virtual ~Temperature();
protected:
	void aleaGenVal();
};


#endif /* TEMPERATURE_H_ */
