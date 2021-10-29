/*
 * Data.h
 *
 *  Created on: Oct 28, 2021
 *      Author: Funcker
 */

#ifndef DATA_H_
#define DATA_H_


/*
 * ESensorType enum :
 * All sensor types
 */
enum class ESensorType
{
	e_temperature_1,
	e_humidity_2,
	e_light_3,
	e_pression_4,
	e_unknown_5
};

/*
 * Data structure :
 * Template structure containing a T type val and
 * the type of the source sensor
 */
template <typename T>
struct Data
{
	ESensorType type = ESensorType::e_unknown_5;
	T val;
};


#endif /* DATA_H_ */
