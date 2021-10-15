/*
 * Humidity.cpp
 *
 *  Created on: 8 oct. 2021
 *      Author: Funcker
 */


#include "Humidity.h"

Data Humidity::aleaGenVal()
{
	srand(time(NULL));

	Data data;
	if (lastData.type == ESensorType::e_unknown_5)
	{
		data = Data {
			type: ESensorType::e_humidity_2,
			floatVal: 45 + (float)(rand() % 80 - 40) * 0.1,
		};
	}
	else
	{
		data = Data {
			type: ESensorType::e_humidity_2,
			floatVal: lastData.floatVal + (rand() % 160 - 80) * 0.01,
		};
	}

	lastData = data;

	return data;
}

Humidity::~Humidity() {
}


