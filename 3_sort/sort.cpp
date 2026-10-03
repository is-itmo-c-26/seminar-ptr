#include "sort.h"

#include <cstdlib>  // std::size_t

void anyswap(void* a, void* b, std::size_t size) {
  char* pa = static_cast<char*>(a);
  char* pb = static_cast<char*>(b);

  for (std::size_t i = 0; i < size; ++i) {
    char tmp = pa[i];
    pa[i] = pb[i];
    pb[i] = tmp;
  }
}

void* byteadd(void* ptr, std::size_t bytes) {
  // кастим в char для побайтовой арифметики
  return static_cast<char*>(ptr) + bytes;
}

void sort(int* begin, std::size_t count, bool(*cmp)(int, int)) {
  if (count < 2) {
    return;
  }

  // quicksort с разбиением Хоара
  std::size_t l = 0;
  std::size_t r = count;
  while (l < r) {
    --r;
    if (cmp(begin[l], begin[r])) {
      // swap
      int tmp = begin[l];
      begin[l] = begin[r];
      begin[r] = tmp;
    }
    ++l;
  }

  sort(begin, l, cmp);
  sort(begin + l, count - l, cmp);
}

void anysort(void* begin, std::size_t size, std::size_t count, bool(*cmp)(const void*, const void*)) {
  if (count < 2) {
    return;
  }

  // quicksort с разбиением Хоара
  std::size_t l = 0;
  std::size_t r = count;
  while (l < r) {
    --r;

    void* l_ptr = byteadd(begin, l * size);
    void* r_ptr = byteadd(begin, r * size);

    if (cmp(l_ptr, r_ptr)) {
      anyswap(l_ptr, r_ptr, size);
    }
    ++l;
  }

  anysort(begin, size, l, cmp);
  anysort(byteadd(begin, l * size), size, count - l, cmp);
}
