#include <stdlib.h>
#include "util.h"

// A + B => K sorted
void merge_2(int A[], size_t A_size, int B[], size_t B_size, int K[]) {
  size_t i = 0; // A index
  size_t j = 0; // B index
  size_t k = 0; // K index

  while (i < A_size && j < B_size) {
    if (A[i] <= B[j]) {
      K[k] = A[i];
      i++;
    } else {
      K[k] = B[j];
      j++;
    }
    k++;
  }

  while (i < A_size) {
    K[k] = A[i];
    i++;
    k++;
  }

  while (j < B_size) {
    K[k] = B[j];
    j++;
    k++;
  }
}

// cc 2-sorted-merge.c util.c && ./a.out
int main(int argc, const char *const argv[argc+1]) {
  int A[] = {4, 5, 6, 7, 8, 9, 21, 22};
  int B[] = {1, 2, 3, 4, 10, 11};

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
