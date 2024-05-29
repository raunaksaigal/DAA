#include<stdio.h>
#include <stdlib.h>

typedef struct items{
  int profit;
  int weight;
  float profit_ratio;
  int index;
}items;


items *item_create(int n){
  items *A = malloc(sizeof(items)*n);
  for (int i=0; i<n; i++) {
    printf("enter item %d the profit and weight: ",i);
    scanf("%d %d", &A[i].profit, &A[i].weight);
    A[i].profit_ratio = A[i].profit/A[i].weight;
    A[i].index = i;
  }
  return A;
}

int cmp(const void* p, const void* q){
  items *a = (items *) p;
  items *b = (items *) q;

  return (a->profit_ratio)-(b->profit_ratio);
}


float knap_sack(int M,int n){
  float x[n], total=0.0;
  items *A;
  A=item_create(n);
 /* for (int i=0; i<n; i++) {
    printf("enter the deadline and profit: ");
    scanf("%d %d", &A[i].deadline, &A[i].profit);
  }*/
    for (int i=0; i<n; i++) {
      printf("item %d profit %d weight %d\n",i,A[i].profit,A[i].weight);
    }

    qsort(A, n, sizeof(items), cmp);
    
    for (int i=0; i<n; i++) 
      x[i] = 0.0;


    int i;
    int U = M;
    for (i=0; i<n; i++) {
        if(A[i].weight>U) break;
        x[i] = 1.0;
        total += A[i].profit;
        U -= A[i].weight;
    printf("\n%f\n", total);
      }
    if (i<n) {
      x[i] = ((float)U)/A[i].weight;
    }
    total += x[i] * A[i].profit;
printf("the optimal soln is \n");

    for(int m=0; m<n; m++){
    printf("of item %d %f \n",A[m].index, x[m]);
      }
  printf("\n");
    return total;

 }



int main(){
  int n;
  printf("enter the nummber of items: ");
  scanf("%d",&n);
  printf("Enter the max weight of knap sack: ");
  int M;
  scanf("%d",&M);
  float total = knap_sack(M,n);
  printf("the total profit is %f",total);
}
