
#include "BitcoinExchange.hpp"

bool DataValue::operator<(const DataValue &in) {
  if (this->year < in.year || this->month < in.year || this->day < in.day)
    return (true);
  return (false);
}

void BitcoinExchange::AddMap(DataValue &key, float &value) {
  _data[key] = value;
}

// Default constructor
BitcoinExchange::BitcoinExchange(void) {
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
