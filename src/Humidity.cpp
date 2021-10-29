/*
 * Humidity.cpp
 *
 *  Created on: 8 oct. 2021
 *      Author: Funcker
 */


#include "Humidity.h"

void Humidity::aleaGenVal()
{
	srand(time(NULL));

	Data<float> newData;
	if (m_data.type == ESensorType::e_unknown_5)
	{
		newData = Data<float> {
			type: ESensorType::e_humidity_2,
			val: 45 + (rand() % 81 - 40) * 0.1,
		};
	}
	else
	{
		float newVal = m_data.val + (rand() % 161 - 80) * 0.01;
		if (newVal < 20) newVal = 20;
		if (newVal > 80) newVal = 80;
		newData = Data<float> {
			type: ESensorType::e_humidity_2,
			val: newVal,
		};
	}

	m_data = newData;
}

Humidity::Humidity()
{
}

Humidity::~Humidity()
{
}


