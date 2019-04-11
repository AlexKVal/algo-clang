#include <stdlib.h>
#include <stdio.h>

#include "util.h"

void swap(int *x, int *y) {
  int tmp = *y;
  *y = *x;
  *x = tmp;
}

void max_heapify(int arr[], size_t i, size_t heap_size) {
  size_t left  = 2 * i + 1;
  size_t right = 2 * i + 2;
  size_t largest = i;

  printf(">>> l:%zu r:%zu i:%zu lg:%zu\n", left, right, i, largest);
  printf(">>> ");
  print_array(arr, heap_size);

  if (left < heap_size && arr[left] > arr[largest]){
    printf("lg = l\n");
    largest = left;
  }

  if (right < heap_size && arr[right] > arr[largest]) {
    printf("lg = r\n");
    largest = right;
  }

  if (largest != i) {
    printf("lg != i\n");
    swap(&arr[i], &arr[largest]);
    max_heapify(arr, i, heap_size);
  }
  printf("___ l:%zu r:%zu i: %zu lg:%zu\n", left, right, i, largest);
  printf("___ ");
  print_array(arr, heap_size);
}
void build_max_heap(int arr[], size_t arr_size) {
  size_t i = arr_size / 2;
  do {
    i--;
    max_heapify(arr, i, arr_size);
  } while(i != 0);
}

// cc binary-heap.c util.c && ./a.out
int main(int argc, const char *const argv[argc + 1]) {
  int arr[] = {4, 3, 6, 8, 2, 1, 0, 8, 8, 5, 7, 3};
  size_t arr_size = sizeof(arr) / sizeof(int);

  print_array_before(arr, arr_size);

  build_max_heap(arr, arr_size);
  build_max_heap(arr, arr_size);
  build_max_heap(arr, arr_size);

  print_array_after(arr, arr_size);

  return EXIT_SUCCESS;
}
