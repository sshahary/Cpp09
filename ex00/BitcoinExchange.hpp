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

#endif