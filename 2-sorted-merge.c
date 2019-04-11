#include <stdlib.h>
#include "util.h"

// A + B => K sorted
void merge_2(int A[], size_t A_size, int B[], size_t B_size, int K[]) {
  size_t i, j, k;

  for (i = j = k = 0; i < A_size && j < B_size; k++) {
    if (A[i] <= B[j]) {
      K[k] = A[i];
      i++;
    } else {
      K[k] = B[j];
      j++;
    }
  }

  for (; i < A_size; i++, k++)
    K[k] = A[i];
  for (; j < B_size; j++, k++)
    K[k] = B[j];
}

// cc 2-sorted-merge.c util.c && ./a.out
int main(int argc, const char *const argv[argc+1]) {
  int A[] = {2, 5, 6, 7, 8, 9};
  int B[] = {1, 2, 3, 10};

  size_t A_size = sizeof(A) / sizeof(int);
  size_t B_size = sizeof(B) / sizeof(int);

  size_t K_size = A_size + B_size;
  int K[K_size];

  print_array(A, A_size);
  print_array(B, B_size);

  merge_2(A, A_size, B, B_size, K);

  print_array(K, K_size);

  return EXIT_SUCCESS;
}
