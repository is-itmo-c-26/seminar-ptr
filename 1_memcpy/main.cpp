#include <cstdlib>  // std::malloc(), std::free(), std::size_t
#include <ctime>    // std::clock(), std::clock_t, CLOCKS_PER_SEC
#include <print>    // std::println()

#include "memory.h"

void test(const void* src, void* dst, std::size_t size) {
  // кол-во итераций для усреднения
  const std::size_t kRepeat = 16;

  std::clock_t time1 = 0;
  std::clock_t time4 = 0;

  for (std::size_t i = 0; i < kRepeat; ++i) {
    std::clock_t point1 = std::clock();
    memcpy1(static_cast<const char*>(src), static_cast<char*>(dst), size / sizeof(char));
    std::clock_t point2 = std::clock();
    memcpy4(static_cast<const int*>(src), static_cast<int*>(dst), size / sizeof(int));
    std::clock_t point3 = std::clock();

    time1 += point2 - point1;
    time4 += point3 - point2;
  }

  // вывод результата
  double time_scale = size * CLOCKS_PER_SEC * kRepeat / (1 << 20);
  std::println("1-byte copy speed: {:.2f} MB/s", time_scale / time1);
  std::println("4-byte copy speed: {:.2f} MB/s", time_scale / time4);

}

int main() {
  // размеры выделяемой памяти
  const std::size_t kSize = 16 * 1024 * 1024;

  // выделение
  void* src = std::malloc(kSize);
  if (src == nullptr) {
    return -1;
  }
  void* dst = std::malloc(kSize);
  if (dst == nullptr) {
    std::free(src);
    return -1;
  }

  // замер скорости
  memset(static_cast<char*>(dst), '\0', kSize);
  test(src, dst, kSize);

  // очистка
  std::free(dst);
  std::free(src);
  return 0;
}
