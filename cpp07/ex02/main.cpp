/*
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
*/

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
