/*
 * Scheduler.h
 *
 *  Created on: 5 oct. 2021
 *      Author: Funcker
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <windows.h>
#include "Server.h"
#include "Sensor.h"
#include "Temperature.h"
#include "Humidity.h"
#include "Light.h"
#include "Pression.h"

class Scheduler {
public:
	Scheduler();
private:
	Server m_server = Server();
	void start();
	void sendDataToServer(Sensor* sensor);
};


#endif /* SCHEDULER_H_ */
