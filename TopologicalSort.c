#include <stdio.h>
#include "./stack.c"
int count = 0;

void startts(int n, int stack[]){
 
}

void dfs(int n, int A[n][n], int status[], int res[], int node, int stack[], int stack_present[]){
  status[node] = 1;
  for(int i=0; i<n; i++){
    if(A[node][i]==1 && i!=node && status[i]==0){
      status[i] = 1;
      printf("discovered %d\n", i);
      dfs(n, A,status, res, i, stack, stack_present);
    }

  

   }
  if(status[node]<2 && stack_present[node]!=1){
      PUSH(stack, node, n);
      stack_present[node]=1;
    }
  
  status[node] = 2;

  printf("visited %d\n", node);
  res[count] = node;
  count++;
}

int main(){
  printf("Enter the number of nodes: ");
  int n;
  scanf("%d", &n);
  int stack[n];
  int stack_present[n];

  int status[n];
  int A[n][n];
  int res[n];
  for (int i=0; i<n; i++) {
    status[i]=0;
    res[i]=0;
    for(int j=0; j<n; j++){
      A[i][j]=0;
    }
  }
  printf("Enter the connections (-1 -1 to exit): ");
  int r,c;
  while(r!=-1 || c!=-1){
    printf("\n>Enter connection:\n");
    scanf("%d %d", &r, &c);
    if(r<n && c<n){
    A[r][c] = 1;

    }else{
      printf("Invalid\n");
    }
  }
  int start;
  printf("Enter the start index: ");
  scanf("%d", &start);
  dfs(n, A, status, res, start, stack, stack_present);
  for(int i=0; i<n; i++){
    if(status[i]!=2)
      dfs(n, A, status, res, i, stack, stack_present);


  }
  /*
  for (int i=0; i<n; i++) {
    printf("%d ", res[i]);
  }*/ 

  while(top!=0){
    printf("%d ",POP(stack, n));
  }

}
