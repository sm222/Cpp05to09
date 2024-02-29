
#include "BitcoinExchange.hpp"

bool DataValue::operator<(const DataValue &in) const {
  if (this->year < in.year)
    return (true);
  if (this->year > in.year)
    return (false);
  if (this->month < in.month)
    return (true);
  if (this->month > in.month)
    return (false);
  return (this->day < in.day);
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
}

static string returnDateString(DataValue const &data) {
  string tmp;
  tmp += std::to_string(data.year) + "-";
  if (data.month > 9)
    tmp += std::to_string(data.month) + "-";
  else
    tmp += "0" + std::to_string(data.month) + "-";
  if (data.day > 9)
    tmp += std::to_string(data.day);
  else
    tmp += "0" + std::to_string(data.day);
  return (tmp);
}

static  void findInMap(map<DataValue, float> &sta, DataValue &toFind, float m) {
  map<DataValue, float>::iterator b = sta.lower_bound(toFind);
  if (b == sta.begin())
    return ;
  b--;
  std::cout << returnDateString(b->first) << " => " << b->second * m << std::endl;
}

static int validStr(const string str) {
  if (str[4] != '-' || str[7] != '-') {
    return (0);
  for (size_t i = 0; i < 4; i++) {
      if (!std::strchr("0123456789", str[i])) {
        return (0);
      }
  }
  }
  for (size_t i = 5; i < 7; i++) {
    if (!std::strchr("0123456789", str[i])) {
      return (0);
    }
  }
  for (size_t i = 8; i < 10; i++) {
    if (!std::strchr("0123456789", str[i])) {
      return (0);
    }
  }
  if (std::strncmp(" | ", str.c_str() + 10, 3) != 0)
    return (0);
  return (1);
}

int  BitcoinExchange::findValue(string value) {
  for (size_t i = 0; i < value.size(); i++) {
    if (!std::strchr("0123456789-|. ", value[i])) {
      std::cout << "Error: bad input => " << value << std::endl;
      return (-1);
    }
  }
  DataValue          tab;
  std::istringstream sep(value);
  char               out;
  string             flo;
  if (!validStr(value)) {
    std::cout << "Error: bad input " << value << std::endl;
    return (-1);
  }
  if ((sep >> tab.year >> out >> tab.month >> out >> tab.day)) {
    float f;
    try {
      flo = value.c_str() + 12;
      f = std::stof(flo);
      if (f > 1000)
        throw std::runtime_error("");
    }
    catch(const std::exception& e) {
      std::cout << "Error: too large a number." << std::endl;
      return (0);
    }
    if (f < 0) {
      std::cout << "Error: not a positive number." << std::endl;
      return (0);
    }
    findInMap(_data, tab, f);
  }
  else {
    std::cout << "nuh uh " << value << std::endl;
    std::cout << tab.year << " " << tab.month << " " << tab.day << std::endl;
    return (false);
  }
  return (0);
}

void BitcoinExchange::AddMap(DataValue &key, float &value) {
  _data[key] = value;
}

// Default constructor
BitcoinExchange::BitcoinExchange(void) {}

std::istream &BitcoinExchange::readInFile(string &dest) {
  return (getline(_inFile, dest));
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
  _dataBase.open("/Users/anboisve/Documents/Cpp05to09/cpp09/ex00/data.csv", std::ios::in);
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
