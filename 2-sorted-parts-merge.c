#include <stdlib.h>
#include "util.h"

// A[lo...md] + A[md+1...hi] => B sorted
void merge_2(int A[], size_t lo, size_t md, size_t hi, int B[]) {
  size_t i = lo;
  size_t j = md + 1;
  size_t k = lo;

  while (k < hi + 1)
    if (i <= md && (j > hi || A[i] <= A[j]))
      B[k++] = A[i++];
    else
      B[k++] = A[j++];
}

// cc 2-sorted-parts-merge.c util.c && ./a.out
int main(int argc, const char *const argv[argc+1]) {
  // [2, 5, 6, 7, 8, 9] and [1, 2, 3, 10]
  int A[] = {2, 5, 6, 7, 8, 9, 1, 2, 3, 10};
  size_t A_size = sizeof(A) / sizeof(int);
  int B[A_size];

  print_array(A, A_size);

  merge_2(A, 0, 5, 9, B);

  print_array(B, A_size);

  return EXIT_SUCCESS;
}
