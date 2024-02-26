#pragma once

#ifndef BITCOINEXCHANGE_HPP_
#define BITCOINEXCHANGE_HPP_

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using std::map;
using std::string;

struct DataValue {
  int     year;
  int     month;
  int     day;
  bool    operator<(const DataValue &in) const;
  bool    operator==(const DataValue &in) const;
};

// Class declaration
class BitcoinExchange {
  public:
    ///|                                                  |
    BitcoinExchange(char *&file);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &rhs);
    void    AddMap(DataValue &data, float &value);
    bool    fileToMap(void);
    bool  findValue(DataValue &toFind, double *out);
    void   printMap(void);
    ~BitcoinExchange(void);
  private:
    BitcoinExchange(void);
    map<DataValue, float> _data;
    std::ifstream         _inFile, _dataBase;
};

#endif // BITCOINEXCHANGE_HPP_
