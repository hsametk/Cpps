#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

class BitcoinExchange {
private:
  std::map<std::string, double> _data;

public:
  BitcoinExchange();
  BitcoinExchange(char *filename);
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();

  void processFile(char *filename);
  void loadData(const std::string &line);
  void printData();
};

#endif