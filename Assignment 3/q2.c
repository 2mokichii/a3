#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpr_ints_rev(const void* a, const void* b) {
  return *(const int*)b - *(const int*)a;
}

typedef struct {
  int x;
  int y;
} point2d;

void swap(void* a, void* b, size_t s)  {
  char* char_a = (char*)a;
  char* char_b = (char*)b;

  for (int i=0;i<s;i++) {
    char tmp = char_a[i];
    char_a[i] = char_b[i];
    char_b[i] = tmp;
  }
}

int gen_insertion_sort(void* ar, int n, size_t size, int (*compare)(const void*, const void*)) {
  int i, j, swaps=0;
  for(i=1; i<n; i++) {
    for(j=i; j>0; j--) {
      int comp = compare(ar[j-1], ar[j]);
      if(comp>0) {
        swap(ar[j-1], ar[j], size);
        swaps++;
      }
    }
  }
  return swaps;
}

int main() {
  int len = 6;
  int ar[6] = {7,3,5,1,11,9};
  int swaps = gen_insertion_sort(ar, len, sizeof(int), cmpr_ints_rev);
  printf("%d\n", swaps);
}