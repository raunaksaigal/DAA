#include <stdio.h>
int F=-1, R=-1;

int q[100];
void view(){
  if(R>=0){
    for(int i=F; i<=R; i++)
      printf("%d ", q[i]);
  }else{
    printf("queue empty\n");
  }
  printf("\n");
}
void Enque(int n){
  if(F==-1 && R==-1){
    F=0;
  }
  R++;
  q[R]=n;
  view();
}

int dequeue(){
  if(F!=-1 && R!=-1){
    int item = q[F];
    F++;
    if(F>R){
      F=-1;
      R=-1;
    }
  printf("dequeued\n");
  return item;
  }
  else{
    printf("empty\n");
    return -1;
  }
}
int n=4;




void bfs(int status[], int start, int res[], int n, int A[n][n]){
  Enque(start);
  int node = start;
  int k=0;
  while(node!=-1){
    node = dequeue();
    printf("Visited node %d\n", node);
    res[k] = node;
    status[node] = 2;
    for(int i=0; i<n; i++){
      if(A[node][i]==1 && i!=node && status[i] == 0){
        printf("discovered node %d\n", i);
        Enque(i);
        status[node]=1;
      }
    }
    k++;
  }

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
  bfs(status, start, res, n, A);
  for (int i=0; i<n; i++) {
    printf("%d ", res[i]);
  
  }
  

}
