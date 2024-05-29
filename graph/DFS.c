#include <stdio.h>
int count = 0;


void dfs(int n, int A[n][n], int status[], int res[], int node){
  status[node] = 1;
  for(int i=0; i<n; i++){
    if(A[node][i]==1 && i!=node && status[i]==0){
      status[i] = 1;

  printf("discovered %d\n", i);
      dfs(n, A,status, res, i);
    }
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
    A[c][r] = 1;

    }else{
      printf("Invalid\n");
    }
  }
  int start;
  printf("Enter the start index: ");
  scanf("%d", &start);
  dfs(n, A, status, res, start);
  for (int i=0; i<n; i++) {
    printf("%d ", res[i]);
  
  }
  

}
