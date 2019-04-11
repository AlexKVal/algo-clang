#include <stdlib.h>
#include <stdio.h>

#include "util.h"

void swap(int *x, int *y) {
  int tmp = *y;
  *y = *x;
  *x = tmp;
}

int parent(int child_idx) {
  return (child_idx - 1) / 2;
}
int left(int parent_idx) {
  return 2 * parent_idx + 1;
}
int right(int parent_idx) {
  return 2 * parent_idx + 2;
}

void sift_down(int arr[], int start, int end) {
  int root = start;

  while (left(root) <= end) { // while the root has at least one child
    int swap_el = root;

    int left_child = left(root);
    if (arr[swap_el] < arr[left_child])
      swap_el = left_child;

    // if there is a right child and that child is greater
    int right_child = right(root);
    if (right_child <= end && arr[swap_el] < arr[right_child])
      swap_el = right_child;

    if (swap_el == root) {
      return; // the root holds the largest element, so we are done
    } else {
      swap(&arr[root], &arr[swap_el]);
      root = swap_el; // repeat to continue sifting down the child now
    }
  }
}

void heapify(int arr[], int arr_size) {
  int last = arr_size - 1;
  int start = parent(last);

  while (start >= 0) {
    // sift down the 'start' node to the proper place in the heap
    sift_down(arr, start, last);
    start--;
  }
}

// cc binary-heap.c util.c && ./a.out
int main(int argc, const char *const argv[argc + 1]) {
  int arr[] = {4, 3, 6, 8, 2, 1, 0, 8, 8, 5, 7, 3};
  // notice: use signed int for count to simplify while loop
  int count = sizeof(arr) / sizeof(int);

  print_array_before(arr, count);

  heapify(arr, count);

  print_array_after(arr, count);

  return EXIT_SUCCESS;
}
