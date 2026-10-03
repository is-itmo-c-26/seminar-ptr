#include <cstdlib>  // std::size_t
#include <print>    // std::print(), std::println()

#include "sort.h"

void dump(const int* data, std::size_t count, const char* name) {
  std::print("{}:", name);
  for (std::size_t i = 0; i < count; ++i) {
    std::print(" {}", data[i]);
  }
  std::println();
}

// типизированный callback для `sort`
bool less(int a, int b) {
  // std::println("less({}, {})", a, b);
  return a < b;
}

// нетипизированный callback для `anysort`
bool greater(const void* a, const void* b) {
  int va = *static_cast<const int*>(a);
  int vb = *static_cast<const int*>(b);
  // std::println("less({}, {})", va, vb);
  return va > vb;
}

int main() {
  int data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  dump(data, 10, "Step 1");

  sort(data, 10, less);
  dump(data, 10, "Step 2");

  anysort(data, sizeof(int), 10, greater);
  dump(data, 10, "Step 3");

  return 0;
}
