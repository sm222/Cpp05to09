
#ifndef DATA_H
# define DATA_H

# include <iostream>
# include <cstdint>

struct Data
{
  int i;
  char c;
};

uintptr_t serialize(Data *data);
Data *deserialize(uintptr_t raw);

#endif // DATA_H
