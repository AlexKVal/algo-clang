#include <stdlib.h>
#include <stdio.h>

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

// expandable to more than two children version
void sift_down_m(int arr[], int start, int last) {
  print_array(arr, last + 1);
  printf("sift_down_m %d[%d] %d\n", arr[start], start, last);

  int left = left_child(start);
  int right = right_child(start);

  if (left > last) return; // if no children, nothing to do

  for(;;) {
    printf(">>> endless loop\n");
    int swap_el = start;

    // compare the left child with its parent
    if (arr[left] > arr[start]) {
      swap_el = left;
      printf("will be swapped: left(%d) > start(%d)\n", arr[left], arr[start]);
    }

    // if the right child exists, compare it with its parent
    if (right <= last && arr[right] > arr[start]) {
      swap_el = right;
      printf("will be swapped: right(%d) > start(%d)\n", arr[right], arr[start]);
    }

    if (swap_el == start) {
      printf("no swap, we are done\n");
      return;
    }

    printf("swap [%d,%d]\n", arr[swap_el], arr[start]);
    swap(&arr[swap_el], &arr[start]);

    sift_down_m(arr, swap_el, last); // re-balance the swapped child's sub-heap
  }
}

void heapify(int arr[], int count) {
  // the balancing process of a binary tree is based upon the idea
  // that all the sub-trees are already balanced
  // so it should start from the very last node of a binary heap to be sure

  // start from the parent of the last element
  int last = count - 1; // 0 based arrays
  int start = parent(last);
  while (start >= 0) {
    printf(">>> next node:%d >= 0\n", start);
    sift_down_m(arr, start, last);
    start--;
  }
}

// cc binary-heap.c util.c && ./a.out
int main(int argc, const char *const argv[argc + 1]) {
  // int arr[] = {4,5,9,8,7};
  int arr[] = {4, 3, 6, 8, 2, 1, 0, 8, 8, 5, 7, 3};
  // notice: use signed int for count to simplify while loop
  int count = sizeof(arr) / sizeof(int);

  print_array_before(arr, count);

  heapify(arr, count);

  print_array_after(arr, count);

  return EXIT_SUCCESS;
}