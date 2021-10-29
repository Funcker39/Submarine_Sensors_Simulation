/*
 * Sensor.h
 *
 *  Created on: 5 oct. 2021
 *      Author: Funcker
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include "Data.h"
#include <stdlib.h>
#include <cmath>
#include <chrono>


/*
 * Sensor class :
 * Abstract class used to define different sensors.
 * It uses a template type T to allow different sensors (inheriting this class)
 * to store different type of values in their data attribute
 */
template <typename T>
class Sensor
{
public:
	Sensor();
	virtual ~Sensor();

	/*
	 * getData method :
	 * Used to update with aleaGenVal() and
	 * return the stored "data" member of the
	 * class with a template type T
	 */
	Data<T> getData();

protected:

	/*
	 * aleaGenVal method :
	 * Used to update the "data" member by simulating
	 * its variations
	 */
	virtual void aleaGenVal();

	/*
	 * data member :
	 * Storing the current data of the sensor
	 */
	Data<T> m_data;
};

template <typename T>
Sensor<T>::~Sensor()
{
}

template <typename T>
Sensor<T>::Sensor()
{
}

template <typename T>
Data<T> Sensor<T>::getData()
{
	aleaGenVal();
	return m_data;
}

template <typename T>
void Sensor<T>::aleaGenVal()
{
}


#endif /* SENSOR_H_ */
