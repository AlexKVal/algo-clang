#include "stdio.h"
#include "util.h"

void print_array(int arr[], size_t size) {
  for (size_t i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void print_array_before(int arr[], size_t size) {
  printf("Before:\t");
  print_array(arr, size);
}

void print_array_after(int arr[], size_t size) {
  printf("After:\t");
  print_array(arr, size);
}
