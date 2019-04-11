#include <stdlib.h>
#include <string.h>
#include "util.h"

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

// left  source arr_from[bgn...mdl-1]
// right source arr_from[mdl...end-1]
// result arr_to[bgn...end-1]
void top_down_merge(int arr_from[], size_t bgn, size_t mdl, size_t end, int arr_to[]) {
  size_t i = bgn;
  size_t j = mdl;

  // while there are elements in the left or right runs
  for (size_t k = bgn; k < end; k++) {
    // if left run head exists and is <= existing right run head
    if (i < mdl && (j >= end || arr_from[i] <= arr_from[j])) {
      arr_to[k] = arr_from[i];
      i++;
    } else {
      arr_to[k] = arr_from[j];
      j++;
    }
  }
}
void top_down_split_merge(int arr_from[], size_t bgn, size_t end, int arr_to[]) {
  if (end - bgn < 2) return; // if the run size == 1, then it is sorted

  size_t mdl = bgn + (end - bgn)/2; // to prevent an overflow

  // recursively sort both runs from arr_to -> arr_from
  top_down_split_merge(arr_to, bgn, mdl, arr_from); // left
  top_down_split_merge(arr_to, mdl + 1, end, arr_from); // right

  // merge the resulting runs from arr_from -> arr_to
  top_down_merge(arr_from, bgn, mdl, end, arr_to);
}
void top_down_merge_sort(int arr[], size_t arr_size) {
  int B[arr_size];
  memcpy(B, arr, arr_size * sizeof(int));
  top_down_split_merge(B, 0, arr_size, arr);
}

// cc merge-sort.c util.c && ./a.out
int main(int argc, const char *const argv[argc+1]) {

  int arr[] = {5, 2, 4, 7, 1, 3, 2, 6};
  size_t arr_size = sizeof(arr) / sizeof(arr[0]);

  print_array_before(arr, arr_size);

  // complexity O(nLogn) b/c it is recursive
  // space complexity O(n)
  // merge_sort(arr, 0, arr_size - 1);
  top_down_merge_sort(arr, arr_size);

  print_array_after(arr, arr_size);

  return EXIT_SUCCESS;
}
