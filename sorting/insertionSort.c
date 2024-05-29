#include <stdio.h>

void insertion_sort(int A[], int n){
  int key =1;
  for(key=1; key<n; key++){
  
      int store = A[key];
      int i=key-1;
      while(i>=0 && A[i]>store){
        A[i+1] = A[i];
        i = i-1;
      }
      A[i+1] = store;
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
  insertion_sort(A, n);
  for (int i=0; i<n; i++) {
    printf("%d ", A[i]);
  }
}
