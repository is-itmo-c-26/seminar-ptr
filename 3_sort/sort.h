#pragma once

#include <cstdlib>  // std::size_t

// `begin` - начало элементов
// `count` - количество элементов
// `cmp`   - функция для сравнения элементов
void sort(int* begin, std::size_t count, bool(*cmp)(int, int));

// `begin` - начало элементов
// `size`  - размер одного элемента
// `count` - количество элементов
// `cmp`   - функция для сравнения элементов
void anysort(void* begin, std::size_t size, std::size_t count, bool(*cmp)(const void*, const void*));
