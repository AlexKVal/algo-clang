#include <stdlib.h>
#include <string.h>
#include "util.h"

void selection_sort(int arr[], size_t arr_size) {
  int sorted_arr[arr_size];
  size_t sorted_idx = 0;

  int unsorted_size = arr_size;

  while (unsorted_size > 0) {
    // find the minimum in the unsorted starting from the first element
    int min = arr[0];
    size_t idx_min = 0;
    for (size_t i = 0; i < unsorted_size; i++) {
      if (arr[i] < min) {
        min = arr[i];
        idx_min = i;
      }
    }

    // remove the min value and shift left the rest of the unsorted array elements
    unsorted_size--;
    for (size_t j = idx_min; j < unsorted_size; j++) {
      arr[j] = arr[j + 1];
    }

    sorted_arr[sorted_idx] = min;
    sorted_idx++;
  }

  // copy the result back
  memcpy(arr, sorted_arr, arr_size * sizeof(int));
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
