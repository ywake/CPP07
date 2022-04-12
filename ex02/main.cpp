#include "Array.hpp"
#include <iostream>
#include <sstream>

template <typename T>
void print(Array<T> const &array)
{
  for (size_t i = 0; i < array.size(); i++) {
    std::cout << "[" << i << "]: " << array[i] << std::endl;
  }
}

int main(void)
{
  std::cout << "--- Array<int> empty; ---" << std::endl;
  Array<int> empty;
  std::cout << "empty.size(): " << empty.size() << std::endl;
  try {
    std::cout << "empty[0]: ";
    (void)empty[0];
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "\n--- Array<int> array(4); ---" << std::endl;
  Array<int> array(4);
  for (size_t i = 0; i < array.size(); i++) {
    array[i] = static_cast<int>(i);
  }
  std::cout << "array.size(): " << array.size() << std::endl;
  print(array);
  try {
    std::cout << "[4]: ";
    std::cout << array[4] << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << "[-1]: ";
    std::cout << array[-1] << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "// array[0] = 100;" << std::endl;
  array[0] = 100;
  std::cout << "[0]: " << array[0] << std::endl;

  std::cout << "\n--- Array<std::string> strs(4); ---" << std::endl;
  Array<std::string> strs(4);
  for (size_t i = 0; i < strs.size(); i++) {
    std::stringstream ss;
    ss << "str" << i;
    ss >> strs[i];
  }
  std::cout << "strs.size(): " << strs.size() << std::endl;
  print(strs);

  std::cout << "\n--- copy/assign ---" << std::endl;
  std::cout << "Array<int> copy(strs);" << std::endl;
  Array<int> copy(array);
  print(copy);

  std::cout << "Array<std::string> assign(1) = {\"old\"};" << std::endl;
  Array<std::string> assign(1);
  assign[0] = "old";
  print(assign);
  std::cout << "assign = strs;" << std::endl;
  assign = strs;
  print(assign);

  return 0;
}
