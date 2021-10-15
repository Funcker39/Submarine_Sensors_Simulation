/*
 * Server.h
 *
 *  Created on: 5 oct. 2021
 *      Author: Funcker
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <iostream>
#include <fstream>
#include "Sensor.h"
#include <sstream>
#include <iomanip>

class Server {
public:
	Server();
	void consoleWrite(Data data);
	void consoleEndl();
	void fileWrite(Data data);
private:
	std::stringstream m_stream;
	std::ofstream m_temperatureFile, m_humidityFile, m_lightFile, m_pressionFile;
	std::string formatData(Data data);
};


#endif /* SERVER_H_ */
