#include <print>  // std::println()

#include "transform.h"

int square(int a) {
  std::println("square({})", a);
  return a * a;
}

int half(int a) {
  std::println("half({})", a);
  return a / 2;
}

void dump(const int* begin, const int* end, const char* name) {
  std::print("{}:", name);
  while (begin != end) {
    std::print(" {}", *begin++);
  }
  std::println();
}

int main() {
  int data[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
  dump(data, data + 8, "Before");

  // первую половину (нечётные) - в квадрат
  transform(data + 0, data + 4, square);
  // вторую половину (нечётные) - делим на 2
  transform(data + 4, data + 8, half);

  dump(data, data + 8, "After");
  return 0;
}
