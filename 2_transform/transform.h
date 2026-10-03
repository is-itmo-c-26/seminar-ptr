#pragma once

// `begin` - указатель на начало
// `end`   - указатель за конец
// `map`   - callback для изменения элементов
void transform(int* begin, int* end, int(*map)(int));
