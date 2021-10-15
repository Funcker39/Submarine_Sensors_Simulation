/*
 * Sensor.h
 *
 *  Created on: 5 oct. 2021
 *      Author: Funcker
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>


enum class ESensorType
{
	e_temperature_1,
	e_humidity_2,
	e_light_3,
	e_pression_4,
	e_unknown_5
};

struct Data
{
	ESensorType type = ESensorType::e_unknown_5;
	float floatVal;
	int intVal;
	bool boolVal;
};


class Sensor
{
public:
	Sensor();
	virtual ~Sensor();
	Data getData();
protected:
	virtual Data aleaGenVal() = 0;
	Data lastData;
};


#endif /* SENSOR_H_ */
