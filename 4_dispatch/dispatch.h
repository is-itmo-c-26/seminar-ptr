#pragma once

#include <cstdlib>  // std::size_t

// Консольная команда
struct Entry {
  const char* name;            // Название
  int (*action)(int, char**);  // Обработчик
  const char* description;     // Описание
};

// Ищет команду по имени, возвращая nullptr при неудаче
const Entry* find(const Entry* entries, std::size_t count, const char* name);
