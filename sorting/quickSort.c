#include <stdio.h>


void swap(int a, int b){
  int temp = a;
  a=b;
  b=temp;
}



int partition(int A[], int start, int end){
  int temp;
  int pivot = A[end];
  int pIndex = start;
  for (int i=start; i<=end-1; i++) {
    if (A[i]<pivot) {
      temp = A[pIndex];
      A[pIndex] = A[i];
      A[i] = temp;
      pIndex++;
    }      
  }
  temp = A[pIndex]; A[pIndex] = A[end]; A[end] = temp;
  return pIndex;

}

void QS(int A[], int start, int end){
  if(start<end){
    int part = partition(A, start, end);
    printf("\n%d\n", part);
    QS(A, start, part-1);
    QS(A, part+1, end);
  }
}



 
int main(){
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  int A[n];
  int i=0;
  while (i<n) {
    printf("Enter the data: ");
    scanf("%d", &A[i]);
    i++;
  }
 for (int i=0; i<n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
  QS(A, 0, n-1);
  for (int i=0; i<n; i++) {
    printf("%d ", A[i]);
  }
}
