#include <stdlib.h>
#include <stdio.h>

void print_array(int arr[], size_t size) {
  for (size_t i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void merge(int arr[], size_t l, size_t m, size_t r) {
  size_t i, j, k, n1, n2;

  // sizes of the left and right parts
  n1 = m - l + 1;
  n2 = r - m;

  // temp arrays
  int L[n1], R[n2];

  // copy the left part to L and the right one to R
  for (i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }

  // merge the temp arrays back into arr
  i = 0; // initial idx of L
  j = 0; // initial idx of R
  k = l; // initial idx of merged
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // copy the remaining elements
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// l - left index, r - right index of the sub-array of the arr
void merge_sort(int arr[], size_t l, size_t r) {
  if (l >= r) return;

  size_t m = (l + r) / 2;

  // first half
  merge_sort(arr, l, m);
  // second half
  merge_sort(arr, m + 1, r);

  // merge the sorted halves
  merge(arr, l, m, r);
}

int main(int argc, const char *const argv[argc+1]) {

  int arr[] = {5, 2, 4, 7, 1, 3, 2, 6};
  size_t arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("Before:\t");
  print_array(arr, arr_size);

  // sort
  merge_sort(arr, 0, arr_size - 1);

  printf("After:\t");
  print_array(arr, arr_size);

  return EXIT_SUCCESS;
}
