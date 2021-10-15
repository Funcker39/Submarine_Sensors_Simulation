/*
 * Light.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Funcker
 */

#ifndef LIGHT_H_
#define LIGHT_H_


#include "Sensor.h"

class Light : public Sensor
{
public:
	virtual ~Light();
protected:
	Data aleaGenVal();
};




#endif /* LIGHT_H_ */
