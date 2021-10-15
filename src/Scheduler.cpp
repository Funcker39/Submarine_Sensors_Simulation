/*
 * Scheduler.cpp
 *
 *  Created on: 5 oct. 2021
 *      Author: Funcker
 */


#include "Scheduler.h"

void Scheduler::start()
{
	Temperature tempSensor = Temperature();
	Humidity humiditySensor = Humidity();
	Light lightSensor = Light();
	Pression pressionSensor = Pression();

	float t = 0;

	while (true) {
		t++;
		sendDataToServer(&tempSensor);
		sendDataToServer(&humiditySensor);
		sendDataToServer(&lightSensor);
		sendDataToServer(&pressionSensor);
		m_server.consoleEndl();
		Sleep(1000);
	}
}

void Scheduler::sendDataToServer(Sensor* sensor)
{
	Data data = sensor->getData();
	m_server.consoleWrite(data);
	m_server.fileWrite(data);
}

Scheduler::Scheduler()
{
	start();
}
