/*
 * Server.cpp
 *
 *  Created on: 5 oct. 2021
 *      Author: Funcker
 */


#include "Server.h"
using namespace std;

Server::Server()
{
}

void Server::consoleWrite(Data data)
{
	switch (data.type) {
		case ESensorType::e_temperature_1 :
		{
			cout << "Temperature : " + formatData(data) << endl;
		}
		break;

		case ESensorType::e_humidity_2 :
		{
			cout << "Humidty : " + formatData(data) << endl;
		}
		break;

		case ESensorType::e_light_3 :
		{
			cout << "Light : " + formatData(data) << endl;
		}
		break;

		case ESensorType::e_pression_4 :
		{
			cout << "Pression : " + formatData(data) << endl;
		}
		break;

		default:
		{
		}
		break;
	}
}

void Server::consoleEndl()
{
	cout << endl;
}

void Server::fileWrite(Data data)
{
	switch (data.type)
	{
		case ESensorType::e_temperature_1 :
		{
			if (!m_temperatureFile.is_open())
			{
				m_temperatureFile.open("temperature_logs.text");
				m_temperatureFile << "Temperature Logs :" << endl;
			}

			m_temperatureFile << formatData(data) << endl;
		}
		break;

		case ESensorType::e_humidity_2 :
		{
			if (!m_humidityFile.is_open())
			{
				m_humidityFile.open("humidity_logs.text");
				m_humidityFile << "Humidity Logs :" << endl;
			}

			m_humidityFile << formatData(data) << endl;
		}
		break;

		case ESensorType::e_light_3 :
		{
			if (!m_lightFile.is_open())
			{
				m_lightFile.open("light_logs.text");
				m_lightFile << "Light Logs :" << endl;
			}

			m_lightFile << formatData(data) << endl;
		}
		break;

		case ESensorType::e_pression_4 :
		{
			if (!m_pressionFile.is_open())
			{
				m_pressionFile.open("pression_logs.text");
				m_pressionFile << "Pression Logs :" << endl;
			}

			m_pressionFile << formatData(data) << endl;
		}
		break;

		default:
			break;
	}
}

string Server::formatData(Data data)
{
	switch (data.type)
	{
		case ESensorType::e_temperature_1 :
		{
			m_stream = stringstream();
			m_stream << std::fixed << setprecision(1) << data.floatVal;
			return m_stream.str() + " °C";
		}
		break;

		case ESensorType::e_humidity_2 :
		{
			m_stream = stringstream();
			m_stream << std::fixed << setprecision(1) << data.floatVal;
			return m_stream.str() + " %";
		}
		break;

		case ESensorType::e_light_3 :
		{
			m_stream = stringstream();
			m_stream << static_cast<int>(data.floatVal);
			return m_stream.str() + " lux";
		}
		break;

		case ESensorType::e_pression_4 :
		{
			m_stream = stringstream();
			m_stream << std::fixed << setprecision(2) << data.floatVal;
			return m_stream.str() + " hPa";
		}
		break;

		default:
		{
			return "";
		}
		break;
		}
}


