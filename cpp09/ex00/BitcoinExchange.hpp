#pragma once

#ifndef BITCOINEXCHANGE_HPP_
#define BITCOINEXCHANGE_HPP_

#include <map>
#include <string>
#include <iostream>
#include <fstream>

using std::map;
using std::string;

struct DataValue {
  short   day;
  int     month;
  int     year;
  bool    operator<(const DataValue &in);
} ;

// Class declaration
class BitcoinExchange {
  public:
    ///|                                                  |
    BitcoinExchange(string file);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &rhs);
    void  AddMap(DataValue &data, float &value);
    ~BitcoinExchange(void);
  private:
    BitcoinExchange(void);
    map<DataValue, float> _data;
    std::ifstream         _inFile, _dataBase; 
};

#endif // BITCOINEXCHANGE_HPP_
