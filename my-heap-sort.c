#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "util.h"

void swap(int *x, int *y) {
  int tmp = *y;
  *y = *x;
  *x = tmp;
}

int parent(int child) {
  return (child - 1) / 2; // int division implicitly floor()
}
int left_child(int parent) {
  return 2 * parent + 1;
}
int right_child(int parent) {
  return 2 * parent + 2;
}

void sift_down(int arr[], int root, int last) {
  for(;;) {
    int swap_el = root;

    int left = left_child(root);
    if (left <= last && arr[left] > arr[root])
      swap_el = left;

    int right = left + 1;
    if (right <= last && arr[right] > arr[swap_el])
      swap_el = right;

    if (swap_el == root) return;

    swap(&arr[swap_el], &arr[root]);
    root = swap_el;
  }
}
void heapify(int arr[], size_t arr_size) {
  int heap_len = arr_size; // use signed int for heap_len to simplify the loop
  for (int start = parent(heap_len - 1); start >= 0; start--) {
    sift_down(arr, start, heap_len - 1);
  }
}

void heap_sort(int arr[], size_t arr_size) {
  int heap_len = arr_size;

  for (size_t i = 0; i < arr_size; i++) {
    // peek top element value
    int top_el = arr[0];

    // delete top element
    int last = heap_len - 1;
    int last_val = arr[last];
    arr[0] = last_val;
    heap_len--;

    // place top element's value to the become free space
    arr[last] = top_el;

    // rebalance heap
    if (heap_len > 1) {
      sift_down(arr, 0, heap_len - 1);
    }
  }
}

// cc my-heap-sort.c util.c && ./a.out
int main(int argc, const char *const argv[argc + 1]) {
  int arr[] = {4, 3, 6, 8, 2, 1, 0, 8, 8, 5, 7, 3};
  size_t arr_size = sizeof(arr) / sizeof(int);

  print_array_before(arr, arr_size);

  heapify(arr, arr_size);

  heap_sort(arr, arr_size);

  print_array_after(arr, arr_size);

  return EXIT_SUCCESS;
}
