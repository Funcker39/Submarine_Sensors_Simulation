/*
 * Temperature.cpp
 *
 *  Created on: 6 oct. 2021
 *      Author: Funcker
 */


#include "Temperature.h"

void Temperature::aleaGenVal()
{
	srand(time(NULL));

	Data<float> newData;
	if (m_data.type == ESensorType::e_unknown_5)
	{
		newData = Data<float> {
			type: ESensorType::e_temperature_1,
			val: 22 + (rand() % 81 - 40) * 0.1,
		};
	}
	else
	{
		float newVal = m_data.val + (rand() % 21 - 10) * 0.02;
		if (newVal < 14) newVal = 14;
		if (newVal > 30) newVal = 30;
		newData = Data<float> {
			type: ESensorType::e_temperature_1,
			val: newVal,
		};
	}

	m_data = newData;
}

Temperature::Temperature()
{
}

Temperature::~Temperature()
{
}
