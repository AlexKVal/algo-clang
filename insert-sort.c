#include <stdlib.h>
#include "util.h"

void insert_sort(int* arr, int arr_size) {
  for (size_t idx_nxt_el = 1; idx_nxt_el < arr_size; idx_nxt_el++) {
    int nxt_el = arr[idx_nxt_el];

    size_t idx_prv_el = idx_nxt_el - 1;
    while (idx_prv_el >= 0 && arr[idx_prv_el] > nxt_el) {
      arr[idx_prv_el + 1] = arr[idx_prv_el];
      idx_prv_el--;
    }
    arr[idx_prv_el + 1] = nxt_el;
  }
}

// cc insert-sort.c util.c && ./a.out
int main(int argc, const char *const argv[argc+1]) {

  int data_arr[] = {5, 13, 4, 16, 27, 3, 2, 35, 1};

  size_t data_arr_size = sizeof(data_arr) / sizeof(data_arr[0]);

  print_array_before(data_arr, data_arr_size);

  // complexity O(n^2) b/c of two nested loops
  // space complexity O(1)
  // useful when the memory is restricted
  // also when the array is mostly pre-sorted (in the right direction)
  insert_sort(data_arr, data_arr_size);

  print_array_after(data_arr, data_arr_size);

  return EXIT_SUCCESS;
}
