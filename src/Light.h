/*
 * Light.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Funcker
 */

#ifndef LIGHT_H_
#define LIGHT_H_

#include "Sensor.h"

/*
 * Light class :
 * Class inheriting the Sensor superclass, using boolean data type.
 */
class Light : public Sensor<bool>
{
public:
	Light();
	virtual ~Light();
protected:
	void aleaGenVal();
};




#endif /* LIGHT_H_ */
