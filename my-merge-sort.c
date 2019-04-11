#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "util.h"

// from_arr[lo...md] sorted merge from_arr[md+1...hi] => to_arr
void merge_2(int from_arr[], size_t lo, size_t md, size_t hi, int to_arr[]) {
  size_t i = lo;
  size_t j = md + 1;
  size_t k = lo;

  while (k < hi + 1)
    if (i <= md && (j > hi || from_arr[i] <= from_arr[j]))
      to_arr[k++] = from_arr[i++];
    else
      to_arr[k++] = from_arr[j++];
}
void split_merge(int aux_arr[], size_t lo, size_t hi, int main_arr[]) {
  if (hi - lo < 1) return;

  size_t md = lo + (hi - lo) / 2;

  // split into the auxiliary array
  split_merge(main_arr, lo, md, aux_arr);
  split_merge(main_arr, md + 1 , hi, aux_arr);

  // merge it back to the main one
  merge_2(aux_arr, lo, md, hi, main_arr);
}
// use just two arrays
// split -> second one
// merge back -> first one
void merge_sort(int main_arr[], size_t arr_size) {
  int aux_arr[arr_size];
  memcpy(aux_arr, main_arr, arr_size * sizeof(int));
  split_merge(aux_arr, 0, arr_size - 1, main_arr);
}

// version with many auxiliary arrays
void split_merge_m(int arr[], size_t arr_size) {
  print_array(arr, arr_size);
  if (arr_size < 2) return;

  int A2[arr_size];
  memcpy(A2, arr, arr_size * sizeof(int));

  size_t lo = 0;
  size_t hi = arr_size - 1;
  size_t md = lo + (hi - lo) / 2;

  split_merge_m(&A2[lo], md + 1);
  split_merge_m(&A2[md + 1], hi - md);

  merge_2(A2, lo, md, hi, arr);
  printf("merged: ");
  print_array(arr, arr_size);
}

// cc my-merge-sort.c util.c && ./a.out
int main(int argc, const char *const argv[argc+1]) {
  int arr[] = {5, 2, 4, 7, 1, 3, 2, 6};
  size_t arr_size = sizeof(arr) / sizeof(arr[0]);

  print_array_before(arr, arr_size);

  // many auxiliary arrays version
  // split_merge_m(arr, arr_size);

  // complexity O(nLogn) b/c it is recursive
  // space complexity O(n)
  merge_sort(arr, arr_size);

  print_array_after(arr, arr_size);

  return EXIT_SUCCESS;
}
