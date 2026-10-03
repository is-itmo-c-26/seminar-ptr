#include <cstdlib>  // std::size_t
#include <cstring>  // std::strcmp()
#include <print>    // std::print(), std::println()

#include "dispatch.h"

int help(int argc, char** argv);
int dog(int argc, char** argv);

// список команд
const Entry kEntries[] = {
  {
    "help", help,
    "prints this message."
  },
  {
    "dog", dog,
    "barks. Add `--loud` to make it loud."
  }
};
// Количество элементов в массиве: размер всего массива на размер одного
// элемента. Вообще не самая хорошая вещь, но ничего лучше у нас пока нет.
const std::size_t kEntryCount = sizeof(kEntries) / sizeof(kEntries[0]);

// команды

int help(int argc, char** argv) {
  std::println("Usage: 4_dispatch [COMMAND]");
  for (std::size_t i = 0; i < kEntryCount; ++i) {
    std::println(" * {}\t - {}", kEntries[i].name, kEntries[i].description);
  }
  return 0;
}

int dog(int argc, char** argv) {
  bool loud = false;

  if (argc > 1) {
    std::println("Incorrect usage. Need `help`?");
    return -1;
  } else if (argc == 1) {
    if (std::strcmp(argv[0], "--loud") != 0) {
      std::println("Incorrect usage. Need `help`?");
      return -1;
    }
    loud = true;
  }

  std::println("{}", loud ? "BARK!" : "bark.");
  return 0;
}

// программа

int main(int argc, char** argv) {
  if (argc == 1) {
    std::println("No command. Need `help`?");
    return -1;
  }
  // пропускаем путь до программы
  argc--;
  argv++;

  // ищем команду
  const Entry* cmd = find(kEntries, kEntryCount, argv[0]);
  if (cmd == nullptr) {
    std::println("Unknown command. Need `help`?");
    return -1;
  }
  // пропускаем команду
  argc--;
  argv++;

  return cmd->action(argc, argv);
}
