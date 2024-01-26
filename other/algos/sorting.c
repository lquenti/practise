#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>
#include<string.h>

/*
 * Algos:
 * - [x] bubble sort
 *   - [ ] write up
 * - [ ] insertion sort
 */

#define i32 int32_t


/* Helpers */
int cmp_i32(const void *a, const void *b) {
  return (*(i32 *)a)-(*(i32 *)b);
}

void swap(void *a, void *b, size_t bytes) {
  void *tmp_buf;
  tmp_buf = malloc(bytes);

  /* memcpy(dest, src, n) */
  memcpy(tmp_buf, a, bytes);
  memcpy(a, b, bytes);
  memcpy(b, tmp_buf, bytes);

  free(tmp_buf);
}

/* *********************************************** */

void bubble_sort(void *base, size_t nmemb, size_t size,
                 int (*cmp)(const void *, const void *)) {
  size_t i, j;
  void *tmp;
  char *basec;
  
  /* To avoid void* arithmetic:
   * Note that char is defined as the smallest addressable unit
   * thus it is perfect for pointer arithmetic
   */
  basec = (char *)base;

  tmp = malloc(size);

  for (i=nmemb; i>1; --i) {
    for (j=0; j<i-1; ++j) {
      if (cmp(basec+j*size, basec+(j+1)*size) > 0) {
        swap(basec+j*size, basec+(j+1)*size, size);
      }
    }
  }

  free(tmp);
}

void insertion_sort(void *base, size_t nmemb, size_t size,
                 int (*cmp)(const void *, const void *)) {
  size_t i, j;
  void *tmp;
  char *basec;

  basec = (char *)base;
  tmp = malloc(size);
  
  for (i=1; i<nmemb; ++i) {
    for (j=0; j<i; ++j) {
      if (cmp(basec+j*size, basec+i*size) > 0) {
        swap(basec+j*size, basec+i*size, size);
      }
    }
  }

  free(tmp);
}

int main() {
  size_t i;
  i32 xs[] = {9,2,4,1,6,5};
  bubble_sort(xs, 6, sizeof(i32), cmp_i32);
  for (i=0; i<6; ++i) {
    printf("%d ", xs[i]);
  }
  printf("\n");

  xs[0]=9; xs[1]=2; xs[2]=4; xs[3]=1; xs[4]=6; xs[5]=5;
  bubble_sort(xs, 6, sizeof(i32), cmp_i32);
  for (i=0; i<6; ++i) {
    printf("%d ", xs[i]);
  }
  printf("\n");
  return 0;
}
