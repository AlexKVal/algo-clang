#include <stdlib.h>
#include <stdio.h>
#include "util.h"

void split(int arr[], size_t lo, size_t hi) {
  if (hi - lo < 1) return;

  size_t md = lo + (hi - lo) / 2;

  printf("[%zu %zu %zu] ", lo, md, hi);
  print_array(&arr[lo], hi - lo + 1);

  split(arr, lo, md);
  split(arr, md + 1, hi);
}

// cc recursively-split.c util.c && ./a.out
int main(int argc, const char *const argv[argc + 1]) {
  int arr[] = {5, 7, 3, 4, 1, 1, 8, 4, 2, 9, 7, 4, 0, 3, 4};
  size_t arr_size = sizeof(arr) / sizeof(int);

  split(arr, 0, arr_size - 1);

  return EXIT_SUCCESS;
}
