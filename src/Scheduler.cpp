/*
 * Scheduler.cpp
 *
 *  Created on: 5 oct. 2021
 *      Author: Funcker
 */


#include "Scheduler.h"

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;
using std::cout; using std::endl;


void Scheduler::run()
{
	int currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();


	/*
	 * Sensor's declarations and initializations
	 */
	Temperature temperature = Temperature();
	PhysicalSensor<typeof(temperature.getData().val)> tempSensor = {
			&temperature,
			currentTime,
			500
	};

	Humidity humidity = Humidity();
	PhysicalSensor<typeof(humidity.getData().val)> humiditySensor = {
			&humidity,
			currentTime,
			2000
	};

	Light light = Light();
	PhysicalSensor<typeof(light.getData().val)> lightSensor = {
			&light,
			currentTime,
			3000
	};

	Pression pression = Pression();
	PhysicalSensor<typeof(pression.getData().val)> pressionSensor = {
			&pression,
			currentTime,
			1000
	};


	while (true)
	{
		currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

		refreshSensor(currentTime, &tempSensor);
		refreshSensor(currentTime, &humiditySensor);
		refreshSensor(currentTime, &lightSensor);
		refreshSensor(currentTime, &pressionSensor);
	}
}

template <typename T>
void Scheduler::refreshSensor(int currentTime_p, PhysicalSensor<T>* sensor_p)
{
	if (currentTime_p - sensor_p->lastRefreshedTime > sensor_p->refreshInterval)
	{
		sendDataToServer(sensor_p);
		sensor_p->lastRefreshedTime = currentTime_p;
	}
}

template <typename T>
void Scheduler::sendDataToServer(PhysicalSensor<T>* sensor_p)
{
	Data<T> data = sensor_p->sensor->getData();
	m_server.consoleWrite(data);
	m_server.fileWrite(data);
	m_server.consoleEndl();
}

Scheduler::Scheduler()
{
	run();
}
