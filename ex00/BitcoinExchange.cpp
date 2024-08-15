/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:12:47 by sshahary          #+#    #+#             */
/*   Updated: 2024/08/15 15:12:48 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <cmath>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbFile)
{
	loadDatabase(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: priceMap(other.priceMap) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		priceMap = other.priceMap;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& dbFile)
{
	std::ifstream file(dbFile.c_str());
	if (!file)
		throw std::runtime_error("Could not open database file.");
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date;
		float price;

		if (std::getline(ss, date, ',') && ss >> price)
			priceMap[date] = price;
	}
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	std::istringstream ss(date);
	int year, month, day;
	char dash1, dash2;

	if (ss >> year >> dash1 >> month >> dash2 >> day)
	{
		if (dash1 == '-' && dash2 == '-' && month >= 1 && month <= 12 && day >= 1 && day <= 31)
			return true;
	}
	return false;
}

float BitcoinExchange::getPrice(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = priceMap.lower_bound(date);

	if (it != priceMap.end() && it->first == date)
		return it->second;

	if (it == priceMap.begin())
		throw std::runtime_error("Date not found in database.");

	--it;
	return it->second;
}

std::string intToString(int n)
{
	std::ostringstream oss;
	oss << n;
	return oss.str();
}

std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, last - first + 1);
}

std::string formatFloat(float value)
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(2) << value;
	std::string str = oss.str();
	size_t pos = str.find_last_not_of('0');
	if (pos != std::string::npos && str[pos] == '.')
		pos--;
	str.erase(pos + 1);
	return str;
}

void BitcoinExchange::processFile(const std::string& inputFile) const
{
	std::ifstream file(inputFile.c_str());
	if (!file)
		throw std::runtime_error("Could not open input file.");

	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date;
		std::string valueStr;
		float value;

		if (std::getline(ss, date, '|') && std::getline(ss, valueStr))
		{
			date = trim(date);
			valueStr = trim(valueStr);

			char* end;
			value = strtof(valueStr.c_str(), &end);

			if (*end != '\0' || end == valueStr.c_str())
			{
				std::cerr << "Error: bad input => " << valueStr << std::endl;
				continue;
			}

			if (value < 0)
			{
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			if (value > 1000)
			{
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}
			if (!isValidDate(date))
			{
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}

			try
			{
				float price = getPrice(date);
				std::cout << date << " => ";
				bool isInteger = (value == static_cast<int>(value));
				if (isInteger)
					std::cout << intToString(static_cast<int>(value));
				else
					std::cout << formatFloat(value);
				std::cout << " = ";
				std::cout << formatFloat(value * price) << std::endl;

			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
}


