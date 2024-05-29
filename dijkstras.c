#include <stdio.h>
typedef struct node{
    int weight,parent,current,d;
}node;

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
        max_edges++;
      }
    }
    else
      printf("invalid edge");
  }
}

node extract_min(int n, node q[]){
  int min=0;
  for(int i=0;i<n;i++){
    if(q[i].weight<q[min].weight){
      min = i;
    }
  }
  printf("min %d\n",min);
  return q[min];
}

void relax(int u, int v, int w, node final[]){
  if(final[v].d>final[u].d+w){
    final[v].d = final[u].d+w;
    final[v].parent = u;
  }
}

void initialize(int n, node final[], node q[]){
  for(int i=0;i<n;i++){
    final[i].parent = -1;
    final[i].d = 999;
    final[i].current = i;
    final[i].weight = 0;
    q[i].parent = -1;
    q[i].d = 999;
    q[i].current = i;
    q[i].weight = 999;
  }
  final[0].parent = 0;
  final[0].d = 0;
  q[0].parent = 0;
  q[0].d = 0;
  q[0].weight = 0;
}


void dijk(int n, int A[][n], node final[n], node q[]){
  //initialize///////////////////
  int q_len=1;
  initialize(n, final, q);
  int status[n];
  for(int i=0;i<n;i++)
    status[i]=0;
  status[0]=1;
  node u;
  //////////////////////////////
  while(q_len!=0){
    //popping from pri_queue///
    u = extract_min(n,q);
    int m=u.current;
    q[m].weight = 999;
    status[m]=2;
    final[m]=u;
    q_len--;
    ///////////////////////////

    for(int i=0; i<n; i++){
      if(A[m][i]!=0){
        int w=A[m][i];
        relax(u.current, i, w, final);
        if(status[i]==0){
          q[i].parent=m;
          q[i].weight=A[m][i];
          q[i].d = final[i].d;
          q_len++;
        }
        else if(status[i]==1){
          continue;
        }
      }
    }
  }
}

int pathfinder(node final[], int v, int cost){
  if(final[v].parent!=0){
    cost+=final[v].d;
    pathfinder(final, final[v].parent, cost);
  }
  printf("|%d->%d|",final[v].parent,final[v].current);
  return cost;
}

int main(){
  int n=5;
  int A[n][n];
  graph_create(n, A);
  node final[n];
  node q[n];
  initialize(n, final, q);
  dijk(n,A,final,q);
  for(int i=0; i<n; i++)
    printf("|%d %d|",i,final[i].d);
  for(int i=0; i<n; i++){
    int cost=0;
    cost = pathfinder(final, i, cost);
    printf("\ncost=%d\n",final[i].d);
    printf("\n");
  }

}
  
