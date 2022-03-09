#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int x;
  int y;
} point2d;

int cmpr_ints_rev(const void* a, const void* b) {
  return *(const int*)b - *(const int*)a;
}

int cmpr_points_L2(const void* a, const void* b) {
  point2d pt1 = *(const point2d*) a;
  point2d pt2 = *(const point2d*) b;
  if (pt1.x != pt2.x)
    return (pt1.x-pt2.x);
  else // pt1.x == pt2.x
    return (pt1.y-pt2.y);
}

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
    j=i-1;
    printf("| i=%d, j=%d ", i, j);
    while(compare(ar+j,ar+i)>0 && j>=0) {
      printf("|| i=%d, j=%d ", i, j);
      printf("| %d swap with %d ", j, i);
      swap(ar+j, ar+i, size);
      swaps++;
      j--;
      printf("j = %d", j);
    }
    printf("\n");
  }
  int* arr = (int*)ar;
  for(int k=0; k<n; k++) {
    printf("%d ",arr[i]);
  }
  
  return swaps;
}

int main() {
  /*
  int len = 6;
  int ar[6] = {7,3,5,1,11,9};
  int ar_correct[6] = {1,3,5,9,11};
  
  for(int i=0; i<6; i++) {
    printf(" %d ", ar[i]);
  }
  printf("\n");
  int swaps = gen_insertion_sort(ar, len, sizeof(int), cmpr_ints_rev);
  printf("\n%d\n", swaps);
  for(int i=0; i<6; i++) {
    printf(" %d ", ar[i]);
  }
  printf("\n\n\n");*/
  
  int lenn = 5;
  point2d arr[5] = {{2,0}, {0,-6}, {5,3}, {3,4}, {3,0}};
  int swapss = gen_insertion_sort(arr, lenn, sizeof(point2d), cmpr_points_L2);
  point2d correct_ans[5] = {{0,-6}, {2,0}, {3,0}, {3,4}, {5,3}};
  printf("  %d\n", swapss);
  
}
