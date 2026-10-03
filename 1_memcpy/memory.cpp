#include "memory.h"

#include <cstdlib>  // std::size_t

void memcpy1(const char* src, char* dst, std::size_t size) {
  for (std::size_t i = 0; i < size; ++i) {
    // эти синтаксисы эквиваленты
    dst[i] = *(src + i);
  }
}

void memcpy4(const int* src, int* dst, std::size_t size) {
  for (std::size_t i = 0; i < size; ++i) {
    dst[i] = *(src + i);
  }
}

void memset(char* dst, char value, std::size_t size) {
  for (std::size_t i = 0; i < size; ++i) {
    dst[i] = value;
  }
}
