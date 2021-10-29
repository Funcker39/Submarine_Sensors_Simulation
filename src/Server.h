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
#include "Data.h"
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>
#include <chrono>
#include <ctime>


/*
 * External function handling the different data types with
 * their respective name and returning a string
 */
template <typename T>
std::string dataToString(Data<T> data_p)
{
	switch (data_p.type) {
		case ESensorType::e_temperature_1 :
		{
			std::stringstream m_stream;
			m_stream << std::setprecision(3) << data_p.val;
			return "Temperature : " + m_stream.str() + " °C";
		}
		break;

		case ESensorType::e_humidity_2 :
		{
			return "Humidty : " + std::to_string((int)round(data_p.val)) + " %";
		}
		break;

		case ESensorType::e_light_3 :
		{
			return "Light : " + std::string(data_p.val ? "ON" : "OFF");
		}
		break;

		case ESensorType::e_pression_4 :
		{
			return "Pression : " + std::to_string(data_p.val) + " hPa";
		}
		break;

		default:
		{
		}
		break;
	}

	return "";
}


/*
 * Server class :
 * Used to store datas in log files and/or show the
 * datas in the console.
 */
class Server {
private:
	std::ofstream m_temperature_file, m_humidity_file, m_light_file, m_pression_file;

public:
	Server()
	{
		m_temperature_file.open("Temperature.txt");
		m_humidity_file.open("Humidity.txt");
		m_light_file.open("Light.txt");
		m_pression_file.open("Pression.txt");
	}


	/*
	 * consoleWrite method :
	 * Used to print formatted data values in the console
	 */
	template <typename T>
	void consoleWrite(Data<T> data_p)
	{
		std::cout << dataToString(data_p) << std::endl;
	}


	/*
	 * fileWrite method :
	 * Used to store each sensor's data logs into a
	 * specific text file with the current date and time.
	 */
	template <typename T>
	void fileWrite(Data<T> data_p)
	{
		std::ofstream* file;
		switch (data_p.type) {
			case ESensorType::e_temperature_1 :
			{
				file = &m_temperature_file;
			}
			break;

			case ESensorType::e_humidity_2 :
			{
				file = &m_humidity_file;
			}
			break;

			case ESensorType::e_light_3 :
			{
				file = &m_light_file;
			}
			break;

			case ESensorType::e_pression_4 :
			{
				file = &m_pression_file;
			}
			break;

			default:
			{
			}
			break;
		}

		auto now = std::chrono::system_clock::now();
		std::time_t now_time = std::chrono::system_clock::to_time_t(now);

		*file << std::ctime(&now_time) << dataToString(data_p) << "\n" << std::endl;
	}


	/*
	 * consoleEndl method :
	 * Used to end a line on the console
	 */
	void consoleEndl()
	{
		std::cout << std::endl;
	}
};



#endif /* SERVER_H_ */
