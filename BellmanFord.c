#include <stdio.h>
#include <limits.h>
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
    final[i].d = INT_MAX;
    final[i].current = i;
    final[i].weight = 0;
    q[i].parent = -1;
    q[i].d = INT_MAX;
    q[i].current = i;
    q[i].weight = INT_MAX;
  }
  final[0].parent = 0;
  final[0].d = 0;
  q[0].parent = 0;
  q[0].d = 0;
  q[0].weight = 0;
}


int blf(int n, int A[][n], node final[n], node q[]){
  //initialize///////////////////
  int q_len=1;
  initialize(n, final, q);
  int status[n];
  for(int i=0;i<n;i++)
    status[i]=0;
  status[0]=1;
  node u;
  //////////////////////////////
  for(int k=0; k<n-1; k++){
    //popping from pri_queue///
    u = extract_min(n,q);
    int m=u.current;
    q[m].weight = INT_MAX;
    status[m]=2;
    final[m]=u;
    q_len--;
    ///////////////////////////

    for(int i=0; i<n-1; i++){
        for(int k=0; k<n; k++){
          for(int l=0; l<n; l++){
            if(A[k][l] != 0){
              int w = A[k][l];
              relax(k, l, w, final);
         if(status[i]==0){
          q[i].parent=m;
          q[i].weight=A[m][i];
          q[i].d = final[i].d;
          q_len++;
        }

            }
          }
          
        }
  
    }
    printf("\n");
    for(int i=0; i<n; i++)
      printf("|%d %d|",final[i].parent,final[i].current);
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(A[i][j]!=0){
          int w=A[i][j];
          if(final[i].d>final[m].d+w)
            return 1;

      }
     
      }
    }
  }
  return 1;
}

void pathfinder(node final[], int v){
  if(final[v].parent!=0){
    pathfinder(final, final[v].parent);
  }
  printf("|%d->%d|",final[v].parent,final[v].current);
}

int main(){
  int n=5;
  int A[n][n];
  graph_create(n, A);
  node final[n];
  node q[n];
  initialize(n, final, q);
  int stat=blf(n,A,final,q);
  if(stat==1){
    for(int i=0; i<n; i++){
      pathfinder(final, i);
      printf(" cost=%d\n", final[i].d);
    }
  }
  else printf("\nCan't be solved...");

}
  
