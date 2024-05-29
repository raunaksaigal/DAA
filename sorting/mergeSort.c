#include <stdio.h>

void merge(int A[], int start, int split, int end);
void MS(int A[], int start, int end);



 
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
  MS(A, 0, n-1);
  for (int i=0; i<n; i++) {
    printf("%d ", A[i]);
  }
}

void merge(int A[], int start, int split, int end){
  int n1 = split-start+1;
  int n2 = end-split;

  int L[n1], R[n2];

  for (int i=0; i<n1; i++)
    L[i] = A[start+i];
  for (int j=0; j<n2; j++)
    R[j] = A[split+j+1];

  int i=0,j=0;
  int k=start;
  while(i<n1 && j<n2 && k<=end){
    if(L[i]<=R[j]){
      A[k] = L[i]; i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
    k++;
  }

  while(i<n1){
    A[k] = L[i];
    k++;
    i++;
  }
  while(j<n2){
    A[k] = R[j];
    j++;
    k++;
  }
}

void MS(int A[], int start, int end){

  if(start<end){
    int mid = (start+end)/2;
    MS(A, start, mid);
    MS(A, mid+1, end);
    merge(A, start, mid, end);
  }

}
