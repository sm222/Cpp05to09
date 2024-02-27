
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
  std::cout << returnDateString(b->first) << " => " << b->second * m << std::endl;
}

int  BitcoinExchange::findValue(string value) {
  for (size_t i = 0; i < value.size(); i++)
  {
    if (!std::strchr("0123456789-|. ", value[i]))
      return (-1);
  }
  DataValue a;
  a.day = 3;
  a.month = 1;
  a.year = 2011;
  findInMap(_data, a, 3);
  std::cout << "valid" << std::endl;
  return (0);
}

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
