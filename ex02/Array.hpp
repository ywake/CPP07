#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
private:
  T *_data;
  std::size_t _size;

public:
  /*
   * Constructor/Destructor
   */
  // Creates an empty array.
  // Array() : _data(new T[0]), _size(0){};

  // Creates an array of n elements initialized by default.
  Array(unsigned int n = 0) : _data(new T[n]), _size(n){};

  virtual ~Array() { delete[] _data; };

  Array(Array const &copy) : _data(new T[copy.size()]), _size(copy.size())
  {
    for (size_t i = 0; i < _size; i++) {
      _data[i] = copy[i];
    }
  }

  /*
   * Operators
   */
  Array &operator=(Array const &other)
  {
    if (this != &other) {
      delete[] _data;
      _size = other.size();
      _data = new T[other.size()];
      for (size_t i = 0; i < _size; i++) {
        _data[i] = other[i];
      }
    }
    return *this;
  }

  T &operator[](std::size_t idx)
  {
    if (idx >= _size)
      throw std::exception();
    return _data[idx];
  }

  T const &operator[](std::size_t idx) const
  {
    if (idx >= _size)
      throw std::exception();
    return _data[idx];
  }

  /*
   * Getter/Setter
   */
  std::size_t size() const { return _size; }

  /*
   * Methods
   */
};

#endif /* ARRAY_HPP */
