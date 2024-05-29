#include <stdio.h>
#include <limits.h>

int mini(int a,int b){return (a<=b) ? a:b;}

void mcm(int n,int p[n+1], int m[][n+1]){
  for(int a=1; a<=n; a++)
    m[a][a]=0;
  for(int l=2; l<=n; l++){
    for(int i=1; i<=n-l+1; i++){
      int j=i+l-1;
      m[i][j]=INT_MAX;
      for (int k=i; k<=j-1; k++) {
        int q =m[i][k]+p[i-1]*p[k]*p[j]+m[k+1][j];
        if(q<m[i][j])
        m[i][j] = q;    
      }
    }
  }
}

int main(){
  int p[]={4,10,3,12,20,7};
  int n=5;
  int m[n+1][n+1];
  mcm(n,p,m);
  for(int i=1; i<=n; i++){
    for(int j=1;j<=n;j++){
      printf("%d ",m[i][j]);
    }
    printf("\n");
  }
  printf("\n%d",m[1][n]);
}
