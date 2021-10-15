/*
 * Sensor.cpp
 *
 *  Created on: 6 oct. 2021
 *      Author: Funcker
 */

#include "Sensor.h"

Sensor::~Sensor()
{
}

Sensor::Sensor()
{
}

Data Sensor::getData()
{
	return aleaGenVal();
}
