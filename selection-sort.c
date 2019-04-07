#include <stdlib.h>
#include <string.h>
#include "util.h"

void swap(int *left, int *right) {
  int tmp = *left;
  *left = *right;
  *right = tmp;
}

void selection_sort(int arr[], size_t arr_size) {
  for (size_t start_idx = 0; start_idx < arr_size; start_idx++) {
    // find the min among the rest of unsorted elements
    size_t idx_min = start_idx;
    for (size_t i = start_idx; i < arr_size; i++) {
      if (arr[i] < arr[idx_min]) {
        idx_min = i;
      }
    }
    swap(&arr[idx_min], &arr[start_idx]);
  }
}

// cc selection-sort.c util.c && ./a.out
int main(int argc, const char *const argv[argc+1]) {

  int arr[] = {5, 2, 4, 7, 1, 3, 2, 6};
  size_t arr_size = sizeof(arr) / sizeof(arr[0]);

  print_array_before(arr, arr_size);

  selection_sort(arr, arr_size);

  print_array_after(arr, arr_size);

  return EXIT_SUCCESS;
}
