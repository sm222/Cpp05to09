
#include "BitcoinExchange.hpp"

bool DataValue::operator<(const DataValue &in) const {
  if (this->day < in.day || this->month < in.month || this->year < in.year)
    return (true);
  return (false);
}

bool DataValue::operator==(const DataValue &in) const {
  if (this->year == in.year && this->month == in.month && this->day == in.day)
    return (true);
  return (false);
}

void  BitcoinExchange::printMap(void) {
  for (map<DataValue, float>::iterator it = _data.begin(); it != _data.end(); it++) {
    std::cout << "Y " << it->first.year << " M " << it->first.month << " D " << it->first.day;
    std::cout << " = " << it->second << std::endl;
  }
  DataValue a;
  a.day = 4;
  a.month = 8;
  a.year = 2021;
  map<DataValue, float>::iterator b = _data.lower_bound(a);
  b--;
  std::cout << "ici " << b->first.day << " "  << b->first.month << " " << b->first.year << " " << b->second << std::endl;
}

/*
bool  BitcoinExchange::findValue(DataValue &toFind, double *out) {
  for (map<DataValue, float>::iterator it = _data.begin(); it != _data.end(); it++) {
    if (it->first == toFind) {
      *out = it->second
      return (true);
    }
  }
}
*/

void BitcoinExchange::AddMap(DataValue &key, float &value) {
  _data[key] = value;
}

// Default constructor
BitcoinExchange::BitcoinExchange(void) {
}

bool BitcoinExchange::fileToMap(void) {
  string    tmp;
  DataValue data;
  
  getline(_dataBase, tmp);
  if ( tmp != "date,exchange_rate")
    return (false);
  while (getline(_dataBase, tmp)) {
    size_t i = 0;
    while (i < tmp.size() && std::strchr("0123456789-,.", tmp[i]))
      i++;
    if (i != tmp.size())
    {
      std::cout << tmp[i] << std::endl;
      return (false);
    }
    std::istringstream sep(tmp);
    char  out;
    if ((sep >> data.year >> out >> data.month >> out >> data.day >> out)) {
      float f;
      sep >> f;
      AddMap(data, f);
    }
    else
      return (false);
  }
  return (true);
}

BitcoinExchange::BitcoinExchange(char *&file) {
  _inFile.open(file, std::ios::in);
  if (_inFile.fail())
    throw std::runtime_error("infile fail");
  _dataBase.open("data.csv", std::ios::in);
  if (_dataBase.fail()) {
    _inFile.close();
    throw std::runtime_error("data.csv fail");
  }
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  *this = other;
  return;
}

// Copy assignment overload
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
  (void)rhs;
  return *this;
}


// Default destructor
BitcoinExchange::~BitcoinExchange(void) {
}
