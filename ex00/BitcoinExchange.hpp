/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:12:57 by sshahary          #+#    #+#             */
/*   Updated: 2024/08/15 15:12:58 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	private:
	std::map<std::string, float> priceMap;
	void loadDatabase(const std::string& dbFile);
	float getPrice(const std::string& date) const;
	bool isValidDate(const std::string& date) const;

	public:
	BitcoinExchange();
	BitcoinExchange(const std::string& dbFile);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void processFile(const std::string& inputFile) const;

};

std::string intToString(int n);
std::string trim(const std::string& str);
std::string formatFloat(float value);

#endif