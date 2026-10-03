#include "transform.h"

#include <print>  // std::print(), std::println()

// `begin` - указатель на начало
// `end`   - указатель за конец
// `map`   - callback для изменения элементов
void transform(int* begin, int* end, int(*map)(int)) {
  while (begin != end) {
    *begin = map(*begin);
    ++begin;
  }
}
