/*
 * Light.cpp
 *
 *  Created on: 8 oct. 2021
 *      Author: Funcker
 */


#include "Light.h"

void Light::aleaGenVal()
{
	srand(time(NULL));

	Data<bool> newData;
	if (m_data.type == ESensorType::e_unknown_5)
	{
		newData = Data<bool> {
			type: ESensorType::e_light_3,
			val: rand() % 100 > 50 ? true : false,
		};
	}
	else
	{
		newData = Data<bool> {
			type: ESensorType::e_light_3,
			val: rand() % 100 > 95 ? !m_data.val : m_data.val,
		};
	}

	m_data = newData;
}

Light::Light()
{
}

Light::~Light()
{
}


