#include <cstdlib>  // std::size_t
#include <print>    // std::print(), std::println()

// `begin` - начало элементов
// `count` - количество элементов
// `cmp`   - функция для сравнения элементов
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

// `begin` - начало элементов
// `size`  - размер одного элемента
// `count` - количество элементов
// `cmp`   - функция для сравнения элементов
void anysort(void* begin, std::size_t size, std::size_t count, bool(*cmp)(const void*, const void*)) {
  if (count < 2) {
    return;
  }

  // quicksort с разбиением Хоара
  std::size_t l = 0;
  std::size_t r = count;
  while (l < r) {
    --r;

    // кастим в char для побайтовой арифметики и swap'а
    char* l_ptr = static_cast<char*>(begin) + l * size;
    char* r_ptr = static_cast<char*>(begin) + r * size;

    if (cmp(l_ptr, r_ptr)) {
      // побайтвый swap
      for (std::size_t i = 0; i < size; ++i) {
        char tmp = l_ptr[i];
        l_ptr[i] = r_ptr[i];
        r_ptr[i] = tmp;
      }
    }
    ++l;
  }

  anysort(begin, size, l, cmp);
  void* mid = static_cast<char*>(begin) + l * size;
  anysort(mid, size, count - l, cmp);
}

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
