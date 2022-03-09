#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assignment3.h"

// generic swap
// assumption: the memory segments don't overlap
void swap(void* a, void* b, size_t s)  {
  char* char_a = (char*)a;
  char* char_b = (char*)b;

  for (int i=0;i<s;i++) {
    char tmp = char_a[i];
    char_a[i] = char_b[i];
    char_b[i] = tmp;
  }

/* // ALTERNATIVE, requires extra space
  void* tmp = malloc(s);
  memcpy(tmp, a, s);
  memcpy(a, b, s);
  memcpy(b, tmp, s);
  free(tmp);
*/
}

int compare(const void* a, const void* b) {
  point2d A = *(point2d*)a, B = *(point2d*)b;
  int ax = A.x;
  int ay = A.y;
  int bx = B.x;
  int by = B.y;

  if((abs(ax)+abs(ay))!=(abs(bx)+abs(by))) {  // if abs sums are different, abs sum1 - abs sum2
    return (abs(ax)+abs(ay))-(abs(bx)+abs(by));  // neg if sum1 goes first, pos if sum2 goes first
  }
  else {  // if abs sums are the same, check if x coords are the same -> if x coords are the same, check if y coords are the same
    if(ax!=bx) {  // if x coord is not the same
      return ax-bx;
    }
    else {
      return ay-by;
    }
  }
}

void sort_points(point2d* ar, int n) {
    qsort(ar, n, sizeof(point2d), compare);
} 


int gen_insertion_sort(void* ar, int n, size_t size, int (*compare)(const void*, const void*)) {
  return -1;
}  


int find(int* A, int start, int end, bool (*pred)(int)) {
  int i=start;
  while(i<end+1) {
    if (pred(A[i])){
      return i;
    }
    i++;
  }
  return -1;
} 


int count(int* A, int start, int end, bool (*pred)(int)) {
  int i, count=0;
  for(i=start; i<end+1; i++) {
    if (pred(A[i])){
      count++;
    }
  }
  if(count>0) {
    return count;
  }
  else{
    return -1;
  }
} 


void map(int* A, int start, int end, int (*f)(int)) {
  int i=start;
  for(i=start; i<end+1; i++) {
    A[i] = f(A[i]);
  }
}


int reduce(int* A, int start, int end, int (*f)(int,int)) {
  int i=start, accumulator=A[start];
  for(i=start+1; i<end+1; i++) {
    accumulator=f(accumulator, A[i]);
  }
  return accumulator;
}  
