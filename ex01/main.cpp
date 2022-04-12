#include <iostream>
#include <string>

#include "iter.hpp"

template <typename T> void print(T const &arg)
{
  std::cout << arg << std::endl;
}

int main(void)
{
  std::string strs[] = {"aaa", "bbb", "ccc"};
  int nums[] = {0, 1, 2, 3, 4};

  ::iter<std::string>(strs, strs->length(), print);
  ::iter<int>(nums, sizeof(nums) / sizeof(int), print);
}
