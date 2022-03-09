#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_even(int x) { return x%2 == 0; }
bool is_positive(int x) { return x>0; }
int square(int x) { return x*x;}
int sum(int x, int y) {return x+y;}
int max(int x, int y) {return x>y?x:y;}


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
  for(i=0; i<6; i++) {
    printf("%d\n", A[i]);
  }
}  


int reduce(int* A, int start, int end, int (*f)(int,int)) {
  int i=start, accumulator=A[start];
  for(i=start+1; i<end+1; i++) {
    accumulator=f(accumulator, A[i]);
  }
  return accumulator;
}

int main() {
  int A[6] = {10,3,-6,5,2,7};
  printf("%d", reduce(A, 0, 5, sum));
}