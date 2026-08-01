#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
  loadDatabase("data.csv");
}
BitcoinExchange::BitcoinExchange(char *filename) {
  loadDatabase(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : _data(other._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other)
    _data = other._data;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// Stringin basindaki ve sonundaki bosluklari temizler
static std::string trim(const std::string &str) {
  size_t first = str.find_first_not_of(" \t");
  if (first == std::string::npos)
    return "";
  size_t last = str.find_last_not_of(" \t");
  return str.substr(first, (last - first + 1));
}

// Tarih formatinin YYYY-MM-DD seklinde olup olmadigini kontrol eder
static bool hasValidDateFormat(const std::string &date) {
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
  return true;
}

// Tarihin gecerli bir takvim tarihi olup olmadigini kontrol eder
static bool isValidDate(const std::string &date) {
  if (!hasValidDateFormat(date))
    return false;

  // "2011-09-13" → year=2011, dash1='-', month=9, dash2='-', day=13
  // >> operatoru tipe gore otomatik ayirir (int→sayi, char→tek karakter)
  int year, month, day;
  char dash1, dash2;
  std::stringstream ss(date);
  ss >> year >> dash1 >> month >> dash2 >> day;

  if (year < 2009 || year > 9999)
    return false;
  if (month < 1 || month > 12)
    return false;
  if (day < 1 || day > 31)
    return false;

  // 30 gunluk aylar icin 31. gun kontrolu
  if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
    return false;

  // Subat icin artik yil kontrolu
  if (month == 2) {
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (day > 29 || (!isLeap && day > 28))
      return false;
  }
  return true;
}

// String'i double'a cevirir, basarisizsa false doner
static bool parseDouble(const std::string &str, double &result) {
  if (str.empty())
    return false;
  std::stringstream ss(str);
  ss >> result;
  char remain;
  if (ss.fail() || ss.get(remain))
    return false;
  return true;
}

/* ========================================================================== */
/*                            Member Functions                                */
/* ========================================================================== */

// CSV dosyasini okuyup _data map'ine yukler
void BitcoinExchange::loadDatabase(const std::string &filename) {
  std::ifstream file(filename.c_str());
  if (!file.is_open())
    return;

  std::string line;
  std::getline(file, line); // ilk satir header, atla
  while (std::getline(file, line))
    loadData(line);
  file.close();
}

// getline ve >> operatoru duz string uzerinde calismaz, stream gerektirir.
// stringstream, string'i stream'e cevirerek getline ile parcalama
// ve >> ile tur donusumu yapmamizi saglar.
void BitcoinExchange::loadData(const std::string &line) {
  std::stringstream ss(line); // string'i stream'e cevir (getline kullanabilmek icin)
  std::string date;
  std::string value;
  if (std::getline(ss, date, ',') && std::getline(ss, value)) {
    double val;
    std::stringstream valStream(value); // "5.8" string'ini double'a cevirmek icin stream'e sar
    valStream >> val;                   // string → double donusumu
    _data[date] = val;                  // map'e ekle: _data["2011-09-13"] = 5.8
  }
}

// Input dosyasini satir satir isler ve bitcoin degerlerini hesaplar
void BitcoinExchange::processFile(char *filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: could not open file." << std::endl;
    return;
  }

  std::string line;
  bool isFirstLine = true;

  while (std::getline(file, line)) {
    // Header satirini atla
    if (isFirstLine) {
      isFirstLine = false;
      if (line == "date | value")
        continue;
    }
    if (trim(line).empty())
      continue;

    // Satiri '|' ayracina gore parcala
    size_t delimPos = line.find('|');
    if (delimPos == std::string::npos) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }

    std::string dateStr = trim(line.substr(0, delimPos));
    std::string valStr  = trim(line.substr(delimPos + 1));

    // Tarih validasyonu
    if (!isValidDate(dateStr)) {
      std::cerr << "Error: bad input => " << dateStr << std::endl;
      continue;
    }

    // Deger validasyonu
    double val;
    if (!parseDouble(valStr, val)) {
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

    // Veritabanindan en yakin tarihi bul (lower_bound)
    std::map<std::string, double>::iterator it = _data.lower_bound(dateStr);
    if (it == _data.end()) {
      if (_data.empty()) {
        std::cerr << "Error: database is empty." << std::endl;
        continue;
      }
      --it; // Son kayda geri don
    } else if (it->first != dateStr) {
      if (it == _data.begin()) {
        std::cerr << "Error: bad input => " << dateStr << std::endl;
        continue;
      }
      --it; // Bir onceki tarihe geri don
    }

    // Sonucu yazdir: tarih => deger = deger * bitcoin_fiyati
    std::cout << dateStr << " => " << val << " = " << (val * it->second)
              << std::endl;
  }
  file.close();
}

void BitcoinExchange::printData() {
  for (std::map<std::string, double>::iterator it = _data.begin();
       it != _data.end(); ++it)
    std::cout << it->first << ":" << it->second << std::endl;
}
