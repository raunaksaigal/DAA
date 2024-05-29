#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int from, current, wgt;
}edge;



int cmp(const void* a, const void* b){
  edge *p = (edge*) a;
  edge *q = (edge*) b;
  return (p->wgt - q->wgt);
}

int findset(int u, int parent[]){
  if(parent[u]==u){
    return u;
  }
  else{
    return findset(parent[u], parent);
  }
}


void kruskals(int n, edge edges[n]){
  qsort(edges, n, sizeof(edge), cmp);
  int parent[n],rank[n];
  for(int i=0;i<n;i++){
    parent[i]=i;rank[i]=0;
  }

  int cost=0;


  for(int i=0;i<n;i++){
    int u=findset(edges[i].from, parent);
    int v=findset(edges[i].current, parent);

    if(u!=v){
      if(rank[u]<rank[v]){
        parent[u] = v;
      }
      else if(rank[u]>rank[v]){
        parent[v]=u;
      }
      else{
        parent[v]=u;
        rank[u] = rank[u]+1;
      }
      cost+=edges[i].wgt;
      printf("|%d->%d|\t%d\n",edges[i].from,edges[i].current,edges[i].wgt);

    }

  }
  printf("\ncost- %d",cost);
}

int main(){
  printf("enter the number of edges:- ");
  int n;
  scanf("%d",&n);
  edge edges[n];
  printf("source destination weight\n");
  for(int i=0; i<n;i++){
    printf("%d>",i);
    scanf("%d %d %d",&edges[i].from,&edges[i].current,&edges[i].wgt);
  }
  kruskals(n, edges);

}


