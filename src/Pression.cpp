/*
 * Pression.cpp
 *
 *  Created on: 8 oct. 2021
 *      Author: Funcker
 */


#include "Pression.h"

void Pression::aleaGenVal()
{
	srand(time(NULL));

		Data<int> newData;
		if (m_data.type == ESensorType::e_unknown_5)
		{
			newData = Data<int> {
				type: ESensorType::e_pression_4,
				val: 1013 + (rand() % 100 > 90 ? rand() % 3 - 1 : 0),
			};
		}
		else
		{
			int newVal = m_data.val + (rand() % 100 > 60 ? rand() % 3 - 1 : 0);
			if (newVal < 988) newVal = 988;
			if (newVal > 1038) newVal = 1038;
			newData = Data<int> {
				type: ESensorType::e_pression_4,
				val: newVal,
			};
		}

		m_data = newData;
}

Pression::Pression()
{
}

Pression::~Pression()
{
}
