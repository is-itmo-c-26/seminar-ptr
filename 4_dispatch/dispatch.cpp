#include "dispatch.h"

#include <cstdlib>  // std::size_t
#include <cstring>  // std::strcmp()

const Entry* find(const Entry* entries, std::size_t count, const char* name) {
  for (std::size_t i = 0; i < count; ++i) {
    if (std::strcmp(entries[i].name, name) != 0) {
      continue;
    }
    return entries + i;
  }
  return nullptr;
}
