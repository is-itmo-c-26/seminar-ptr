#include <cstdlib>  // std::malloc(), std::free(), std::size_t
#include <ctime>    // std::clock(), std::clock_t, CLOCKS_PER_SEC
#include <print>    // std::println()

void memcpy1(const char* src, char* dst, std::size_t size) {
  for (std::size_t i = 0; i < size; ++i) {
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

int main() {
  // настройки
  const std::size_t kSize = 16 * 1024 * 1024;  // размеры выделяемой памяти
  const std::size_t kRepeat = 16;              // итерации для замера скорости

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

  // инициализация
  memset(static_cast<char*>(dst), '\0', kSize);
  std::clock_t time1 = 0;
  std::clock_t time4 = 0;

  // замер скорости
  for (std::size_t i = 0; i < kRepeat; ++i) {
    std::clock_t point1 = std::clock();
    memcpy1(static_cast<const char*>(src), static_cast<char*>(dst), kSize / sizeof(char));
    std::clock_t point2 = std::clock();
    memcpy4(static_cast<const int*>(src), static_cast<int*>(dst), kSize / sizeof(int));
    std::clock_t point3 = std::clock();

    time1 += point2 - point1;
    time4 += point3 - point2;
  }

  // вывод результата
  const double kTimeScale = kSize * CLOCKS_PER_SEC * kRepeat / (1 << 20);
  std::println("1-byte copy speed: {:.2f} MB/s", kTimeScale / time1);
  std::println("4-byte copy speed: {:.2f} MB/s", kTimeScale / time4);

  // очистка
  std::free(dst);
  std::free(src);
  return 0;
}
