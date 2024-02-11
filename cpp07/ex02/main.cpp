#include "Array.hpp"

int main(void) {
  Array<char> char_list(20);
  Array<char> char_list2;

  try
  {
    char_list[0] = 'A';
    std::cout << char_list.size() << std::endl;
    std::cout << "list 1" << char_list[0] << std::endl;
    std::cout << '|' << char_list.getArray() << '|' << std::endl;
    char_list2 = char_list;
    std::cout << "list 2" << char_list2[0] << std::endl;
    std::cout << '|' << char_list2.getArray() << '|' << std::endl;

    char_list[40] = 'M';
  }
  catch(const std::exception& e)
  {
    std::cout << e.what() << std::endl;
  }
}