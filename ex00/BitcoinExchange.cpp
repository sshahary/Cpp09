#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <iomanip>
#include <cstdlib> // for atof

// Default constructor
BitcoinExchange::BitcoinExchange() {}

// Parameterized constructor
BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    loadDatabase(dbFile);
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : priceMap(other.priceMap) {}

// Copy assignment operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        priceMap = other.priceMap;
    }
    return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& dbFile) {
    std::ifstream file(dbFile.c_str());
    if (!file) {
        throw std::runtime_error("Could not open database file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        float price;

        if (std::getline(ss, date, ',') && ss >> price) {
            priceMap[date] = price;
        }
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    std::istringstream ss(date);
    int year, month, day;
    char dash1, dash2;

    if (ss >> year >> dash1 >> month >> dash2 >> day) {
        if (dash1 == '-' && dash2 == '-' && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
            return true;
        }
    }
    return false;
}

float BitcoinExchange::getPrice(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = priceMap.lower_bound(date);
    
    // Check if we found an exact match
    if (it != priceMap.end() && it->first == date) {
        return it->second;
    }

    // If we don't have an exact match, move to the closest earlier date
    if (it == priceMap.begin()) {
        throw std::runtime_error("Date not found in database.");
    }

    --it;
    return it->second;
}

void BitcoinExchange::processFile(const std::string& inputFile) const {
    std::ifstream file(inputFile.c_str());
    if (!file) {
        throw std::runtime_error("Could not open input file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string valueStr;
        float value;

        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
            date.erase(date.find_last_not_of(" \n\r\t") + 1); // trim trailing spaces
            value = static_cast<float>(atof(valueStr.c_str()));
            if (value < 0) {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            if (value > 1000) {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }
            if (!isValidDate(date)) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }

            try {
                float price = getPrice(date);
                std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << value * price << std::endl;
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}
