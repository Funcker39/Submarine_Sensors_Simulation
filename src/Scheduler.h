/*
 * Scheduler.h
 *
 *  Created on: 5 oct. 2021
 *      Author: Funcker
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <windows.h>
#include <iostream>
#include <chrono>
#include "Server.h"
#include "Sensor.h"
#include "Temperature.h"
#include "Humidity.h"
#include "Light.h"
#include "Pression.h"


/*
 * PhysicalSensor struct :
 * A structure to store a sensor and define its
 * "physical characteristics" : lastRefreshedTime" and
 * "refreshInterval"
 */
template <typename T>
struct PhysicalSensor {
	Sensor<T>* sensor;
	int lastRefreshedTime;
	int refreshInterval;
};

/*
 * Scheduler class :
 * Used to store physical sensors, update and send their value
 * to the server
 */
class Scheduler {
public:
	/*
	 * Default constructor, calling the private method "run()"
	 */
	Scheduler();
private:
	/*
	 * The server associated with the Scheduler
	 */
	Server m_server = Server();

	/*
	 * run method :
	 * Main method of scheduler, automatically called
	 * when instantiating the class and running an infinite loop
	 * to update and send sensor's data to the server
	 */
	void run();

	/*
	 * sendDataToServer method :
	 * Used to send the physical sensor's sensor data to
	 * the Server "m_server"
	 */
	template <typename T>
	void sendDataToServer(PhysicalSensor<T>* sensor_p);

	/*
	 * refreshSensor method :
	 * Used to call the method "sendDataToServer()" according
	 * to the physical sensor refresh interval
	 */
	template <typename T>
	void refreshSensor(int currentTime_p, PhysicalSensor<T>* sensor_p);
};


#endif /* SCHEDULER_H_ */
