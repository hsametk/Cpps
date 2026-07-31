#include "BitcoinExchange.hpp"


static std::string trim(const std::string &str) {
  size_t first = str.find_first_not_of(" \t");
  if (first == std::string::npos)
    return "";
  size_t last = str.find_last_not_of(" \t");
  return str.substr(first, (last - first + 1));
}

static bool isValidDate(const std::string &date) {
  if (date.length() != 10)
    return false;
  if (date[4] != '-' || date[7] != '-')
    return false;
  for (int i = 0; i < 10; ++i) {
    if (i == 4 || i == 7)
      continue;
    if (date[i] < '0' || date[i] > '9')
      return false;
  }

  int year, month, day;
  std::stringstream ss(date);
  char dash1, dash2;
  ss >> year >> dash1 >> month >> dash2 >> day;

  if (year < 2009 || year > 9999)
    return false; // Bitcoin started in 2009
  if (month < 1 || month > 12)
    return false;
  if (day < 1 || day > 31)
    return false;

  if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
    return false;
  if (month == 2) {
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (day > 29 || (!isLeap && day > 28))
      return false;
  }
  return true;
}

BitcoinExchange::BitcoinExchange() {
  std::ifstream file("data.csv");
  std::string line;
  if (file.is_open()) {
    std::getline(file, line); // skip header
    while (std::getline(file, line))
      this->loadData(line);
    file.close();
  }
}

BitcoinExchange::BitcoinExchange(char *filename) {
  std::ifstream file(filename);
  std::string line;
  if (file.is_open()) {
    std::getline(file, line); // skip header
    while (std::getline(file, line))
      this->loadData(line);
    file.close();
  }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  this->_data = other._data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other)
    this->_data = other._data;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::processFile(char *filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: could not open file." << std::endl;
    return;
  }

  std::string line;
  bool isFirstLine = true;
  while (std::getline(file, line)) {
    if (isFirstLine) {
      isFirstLine = false;
      if (line == "date | value")
        continue;
    }
    if (trim(line).empty())
      continue;

    size_t delimPos = line.find('|');
    if (delimPos == std::string::npos) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }

    std::string dateStr = trim(line.substr(0, delimPos));
    std::string valStr = trim(line.substr(delimPos + 1));

    if (!isValidDate(dateStr)) {
      std::cerr << "Error: bad input => " << dateStr << std::endl;
      continue;
    }

    double val;
    std::stringstream ss(valStr);
    ss >> val;

    char remain;
    if (valStr.empty() || ss.fail() || ss.get(remain)) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }

    if (val < 0) {
      std::cerr << "Error: not a positive number." << std::endl;
      continue;
    }
    if (val > 1000) {
      std::cerr << "Error: too large a number." << std::endl;
      continue;
    }

    std::map<std::string, double>::iterator it = _data.lower_bound(dateStr);
    if (it == _data.end()) {
      if (_data.empty()) {
        std::cerr << "Error: database is empty." << std::endl;
        continue;
      }
      --it;
    } else if (it->first != dateStr) {
      if (it == _data.begin()) {
        std::cerr << "Error: bad input => " << dateStr << std::endl;
        continue;
      }
      --it;
    }

    std::cout << dateStr << " => " << val << " = " << (val * it->second)
              << std::endl;
  }
  file.close();
}

void BitcoinExchange::loadData(const std::string &line) {
  std::stringstream ss(line);
  std::string date;
  std::string value;
  if (std::getline(ss, date, ',') && std::getline(ss, value)) {
    double val;
    std::stringstream val_ss(value);
    val_ss >> val;
    this->_data[date] = val;
  }
}

void BitcoinExchange::printData() {
  for (std::map<std::string, double>::iterator it = this->_data.begin();
       it != this->_data.end(); it++)
    std::cout << it->first << ":" << it->second << std::endl;
}
