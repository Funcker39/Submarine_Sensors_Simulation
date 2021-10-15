/*
 * Pression.cpp
 *
 *  Created on: 8 oct. 2021
 *      Author: Funcker
 */


#include "Pression.h"

Data Pression::aleaGenVal()
{
	srand(time(NULL));

	Data data;
	if (lastData.type == ESensorType::e_unknown_5)
	{
		data = Data {
			type: ESensorType::e_pression_4,
			floatVal: 1013.25 + (rand() % 1 - .5) * 0.05,
		};
	}
	else
	{
		data = Data {
			type: ESensorType::e_pression_4,
			floatVal: lastData.floatVal + (rand() % 6 - 3) * 0.01,
		};
	}

	lastData = data;

	return data;
}

Pression::~Pression() {
}
