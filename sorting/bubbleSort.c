#include <stdio.h>

void bubbleSort(int A[], int n){
  int temp;
  for(int i=0; i<n; i++){
    for (int j=0; j<n-i-1; j++){
      if(A[j]>A[j+1]){
        temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
      }
    }
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
  bubbleSort(A, n);
  printf("\n\n");
  for (int i=0; i<n; i++) {
    printf("%d ", A[i]);
  }
}
