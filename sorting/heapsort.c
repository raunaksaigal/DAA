#include <stdio.h>


void swap(int a, int b){
  int temp = a;
  a=b;
  b=temp;
}

void heapify(int n, int A[n], int i){
  int max=i,temp, l=2*i, r=l+1;
  if(A[l]>A[max] && l<=n)
    max = l;
  if(A[r]>A[max] && r<=n)
    max = r;
  if(max!=i){
    temp = A[max]; A[max]=A[i];A[i]=temp;
    heapify(n, A, max);

  }
 for(int i=1; i<= n; i++)
    printf("%d ", A[i]);
  printf("\n");
}
void maxheap(int n, int A[]){
  for(int i=n/2; i>0; i--)
    heapify(n, A, i);
}

void heapsort(int a[], int n){
  int t;
  for (int i=n; i>=1; i--) {
    t=a[1];
    a[1]=a[i];
    a[i]=t;
    maxheap(i-1, a);  
  }
  maxheap(0,a); 
}



int main(){
  printf("Enter the size of the heap: ");
  int n;
  scanf("%d", &n);
  int A[n+1];
  A[0] = 0;
  for(int i=1; i<=n; i++){
    printf("Enter in position %d: ",i);
    scanf("%d", &A[i]);
  }
  heapsort( A,n);
  for(int i=1; i<= n; i++)
    printf("%d ", A[i]);

}
