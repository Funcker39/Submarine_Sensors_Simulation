/*
 * Light.cpp
 *
 *  Created on: 8 oct. 2021
 *      Author: Funcker
 */


#include "Light.h"

Data Light::aleaGenVal()
{
	srand(time(NULL));

	Data data;
	if (lastData.type == ESensorType::e_unknown_5)
	{
		data = Data {
			type: ESensorType::e_light_3,
			floatVal: 200 + (float)(rand() % 100 - 50),
		};
	}
	else
	{
		data = Data {
			type: ESensorType::e_light_3,
			floatVal: lastData.floatVal + (rand() % 10 - 5),
		};
	}

	lastData = data;

	return data;
}

Light::~Light() {
}


