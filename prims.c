#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct{
  int parent,current,key;
}node;

typedef struct{
  int from,weight;
}edge;

void makequeue(int n, int A[][n], edge q[]){
  for(int i=0; i<n; i++){
    q[i].weight = INT_MAX;
    q[i].from = -1;
  }
}

int extract_min(edge q[], int n){
  int min=0;
  for(int i=0; i<n; i++){
    if(q[i].weight <= q[min].weight){
      min = i;
    }
  }
  return min;
}
void vertex_print(int f_len, node final[]){
  int cost=0;
  for(int i=0; i<f_len; i++){
    printf("|%d->%d|",final[i].parent, final[i].current);
    cost = cost+final[i].key;
  }
}



void prims(int n, int A[][n]){
  edge q[n];
  int qlen = 0;
  node final[n];
  int f_key=0;
  int status[n];
  for(int i=0; i<n; i++){
    status[i]=0;
    q[i].from = -1;
    q[i].weight=INT_MAX;
  }

  //initialize first index into queue
  q[0].weight = 0;
  q[0].from = 0;
  qlen++;
  status[0]=1;

  while (qlen!=0){
    int u = extract_min(q, n);
    printf("min->%d\n",u);
    qlen--;
    if(status[u] == 1){
      final[f_key].parent = q[u].from;
      final[f_key].current = u;
      final[f_key].key = q[u].weight;
      f_key++;
      q[u].weight = INT_MAX;
    }
    status[u]=2;

    for(int i=0; i<n; i++){
      if(A[u][i] > 0 && status[i]<2){
        if(status[i]<1){
          q[i].from=u;
          q[i].weight=A[u][i];
          printf("item %d in q with wgt %d\n",i,q[i].weight);
          qlen++;
         
          status[i]=1;
        }
        else if(A[u][i]<q[i].weight){
          q[i].weight = A[u][i];
          q[i].from = u;
        }
      }
    }
    for(int m=0; m<n; m++)
      printf("|%d, %d|", m, q[m].weight);
    printf("\n");
  }
  vertex_print(f_key, final);
}


void graph_create(int n, int A[][n]){
  printf("Create graph\nEnter connections in the following manner: source dest weight\nuse -1 -1 -1 to exit\nEnter connections and weight\n");
  int max_edges = 0;
  int i,j,w;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        A[i][j] = 0;
    }
  }
  while(max_edges<=n*(n-1)){
    scanf("%d %d %d",&i,&j,&w);
   
    if(i<n && j<n){
      if(i==-1 && j==-1 && w==-1){
         break;
      }
      else{
        A[i][j] = w;
        A[j][i] = w;
        max_edges++;
      }
    }
    else
      printf("invalid edge");
  }
}


int main(){
  int n=8;
  int A[n][n];
  graph_create(n, A);
  prims(n, A);

}
