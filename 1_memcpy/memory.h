#pragma once

#include <cstdlib>  // std::size_t

void memcpy1(const char* src, char* dst, std::size_t size);

void memcpy4(const int* src, int* dst, std::size_t size);

void memset(char* dst, char value, std::size_t size);
