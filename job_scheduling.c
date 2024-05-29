#include <stdio.h>
#include <stdlib.h>

typedef struct job{
  int index;
  int deadline;
  int profit;
}job;
int max=0;
int mini(int a, int b){
  if(a<b)
    return a;
  else return b;
}
  
job *job_create(int n){
  job *A = malloc(sizeof(job)*n);
  for (int i=0; i<n; i++) {
    printf("enter job %d the deadline and profit: ",i+1);
    scanf("%d %d", &A[i].deadline, &A[i].profit);
    A[i].index = i+1;
    if(max<A[i].deadline)
      max=A[i].deadline;
  }
  return A;
}

int cmp(const void* p, const void* q){
  job *a = (job *) p;
  job *b = (job *) q;

  return (b->profit)-(a->profit);
}

int* job_schedule(int n){
  job *A;
  A=job_create(n);
  int *time_slot = malloc(sizeof(int)*max);
  for(int i=0; i<max; i++)
    time_slot[i] = 0;
 /* for (int i=0; i<n; i++) {
    printf("enter the deadline and profit: ");
    scanf("%d %d", &A[i].deadline, &A[i].profit);
  }*/
   
  qsort(A, n, sizeof(job), cmp);
  for (int i=0; i<n; i++) {
    printf("job %d deadline %d profit %d\n",A[i].index,A[i].deadline,A[i].profit);
  }

  int k=0,ind=0;
  for(int i=0; i<n; i++){
    k = mini(A[i].deadline, max);
    ind = k-1;
    while(ind>=0){
      if (time_slot[ind]==0){
        time_slot[ind] = A[i].index;
        break;
      }
      ind-=1;
    }
  }
  return time_slot;
}

int main(){
  int n;
  printf("enter the nummber of jobs: ");
  scanf("%d",&n);
  int *time;
  time = job_schedule(n);
  printf("the timeline of jobs is:- ");
  for (int i=0; i<max; i++) {
    printf("%d ",time[i]);
  }
   
}
