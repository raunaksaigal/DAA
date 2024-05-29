#include <stdio.h>


void swap(int a, int b){
  int temp = a;
  a=b;
  b=temp;
}

void selectionSort(int A[], int n){
  int temp;
  for(int i=0; i<n; i++){
    printf("\n%d\n", A[i]);
    for(int j=i; j<n; j++){
     printf("%d ", A[j]);

      if(A[j]<A[i]){
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
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
  selectionSort(A, n);
  printf("\n\n");
  for (int i=0; i<n; i++) {
    printf("%d ", A[i]);
  }
}
