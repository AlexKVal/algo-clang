#include <stdlib.h>
#include "util.h"

void quick_sort(int arr[], size_t arr_size) {
  //
}

// cc quick-sort.c util.c && ./a.out
int main(int argc, const char *const argv[argc + 1]) {
  int arr[] = {145, 22, 45, 983, 1023, 55, 2, 44, 44, 123};
  size_t arr_size = sizeof(arr) / sizeof(int);

  print_array_before(arr, arr_size);

  quick_sort(arr, arr_size);

  print_array_after(arr, arr_size);

  return EXIT_SUCCESS;
}
