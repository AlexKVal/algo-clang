#include <stdlib.h>
#include "util.h"

typedef enum { false, true } bool;

void swap(int *left, int *right) {
  int tmp = *left;
  *left = *right;
  *right = tmp;
}

void bubble_sort(int arr[], size_t arr_size) {
  bool finished = false;

  while (!finished) {
    finished = true;

    for (size_t i = 1; i < arr_size; i++) {
      if (arr[i-1] > arr[i]) {
        swap(&arr[i-1], &arr[i]);
        finished = false;
      }
    }
  }
}

// cc bubble-sort.c util.c && ./a.out
int main(int argc, const char *const argv[argc + 1]) {

  int arr[] = {5, 2, 4, 7, 1, 3, 2, 6};
  size_t arr_size = sizeof(arr) / sizeof(arr[0]);

  print_array_before(arr, arr_size);

  // complexity O(n^2) b/c of two nested loops
  // space complexity O(1)
  // Bubble sort also interacts poorly with modern CPU hardware.
  // It produces at least twice as many writes as insertion sort, twice as many cache misses,
  // and asymptotically more branch mispredictions
  // Insertion sort performs considerably better even on random lists
  bubble_sort(arr, arr_size);

  print_array_after(arr, arr_size);

  return EXIT_SUCCESS;
}
