#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int x;
  int y;
} point2d;

int* compare(void* a, void* b) {
    point2d A = *(point2d*)a, B = *(point2d*)b;
    int ax = abs(A.x);
    int ay = abs(A.y);
    int bx = abs(B.x);
    int by = abs(B.y);

    if((ax+ay)!=(bx+by)) {  // if sums are different, sum1-sum2
        return (ax+ay)-(bx+by);  // neg if sum1<sum2 (sum1 goes first), pos if sum1>sum2 (sum2 goes first)
    }
    else {  // if sums are the same, check if x coords are the same -> if x coords are the same, check if y coords are the same
        if(ax!=bx) {  // if x coord is not the same
            return ax-bx;
        }
        else {
            if(ay!=by) {
                return ay-by;
            }
        }
    }
}

void sort_points(point2d* ar, int n) {
    qsort(ar, n, sizeof(point2d), compare);
}

int main () {
    int len1 = 8;
    int len2 = 7;
    point2d A[] = {{3,2}, {3,2}, {3,-2}, {4,-1}, {5,0}, {-3,-2},  {-3,2}, {5,0}};
    point2d B[] = {{-3,-2}, {-3,2}, {3,-2}, {3,2}, {3,2}, {4,-1}, {5,0}, {5,0}};
    point2d C[] = {{3,2}, {7,1}, {1,1}, {-3,4}, {-5,0}, {-6,2}, {-3,4}};
    point2d D[] = {{1,1}, {-5,0}, {3,2}, {-3,4}, {-3,4}, {-6,2}, {7,1}};
    sort_points(A,len1);
    printf("your sort: ");
    for(int i=0;i<len1;i++) printf("(%d, %d) ", A[i].x, A[i].y);
    printf("\n answer: ");
    for(int i=0;i<len1;i++) printf("(%d, %d) ", B[i].x, B[i].y);
    printf("\n");
    sort_points(C,len2);
    for(int i=0;i<len2;i++) printf("(%d, %d) ", C[i].x, C[i].y);
    printf("\n answer: ");
    for(int i=0;i<len2;i++) printf("(%d, %d) ", D[i].x, D[i].y);
    printf("\n");
}