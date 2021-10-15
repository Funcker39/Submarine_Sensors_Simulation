/*
 * Temperature.cpp
 *
 *  Created on: 6 oct. 2021
 *      Author: Funcker
 */


#include "Temperature.h"

Data Temperature::aleaGenVal()
{
	srand(time(NULL));

	Data data;
	if (lastData.type == ESensorType::e_unknown_5)
	{
		data = Data {
			type: ESensorType::e_temperature_1,
			floatVal: 22 + (float)(rand() % 80 - 40) * 0.1,
		};
	}
	else
	{
		data = Data {
			type: ESensorType::e_temperature_1,
			floatVal: lastData.floatVal + (rand() % 20 - 10) * 0.02,
		};
	}


	lastData = data;

	return data;
}

Temperature::~Temperature()
{
}
