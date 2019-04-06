#include <stdlib.h>
#include <stdio.h>

void insert_sort(int arr_size, int* arr) {
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

int main(int argc, const char *const argv[argc+1]) {

  int data_arr[] = {5, 13, 4, 16, 27, 3, 2, 35, 1};

  size_t data_arr_size = sizeof(data_arr) / sizeof(data_arr[0]);

  printf("Before:\t");
  for (size_t i = 0; i < data_arr_size; i++) {
    printf("%d ", data_arr[i]);
  }

  insert_sort(data_arr_size, data_arr);

  printf("\nAfter:\t");
  for (size_t i = 0; i < data_arr_size; i++) {
    printf("%d ", data_arr[i]);
  }
  puts("\n");

  return EXIT_SUCCESS;
}
