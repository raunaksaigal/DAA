#include <stdio.h>
int top = 0;
void PUSH(int A[], int num, int l){
	if(top>l) printf("stack full\n");
	else{
		top = top+1;
		A[top] = num;
    printf("%d in stack\n",num);
	}
}

int POP(int A[], int l){
	if(top<1) printf("stack empty\n");
	else{
		int item = A[top];
		top = top-1;
		return item;
	}
	return -1;
}
/*
int main(){
	top = 0;
	int l;
	printf("enter the length of stack: ");
	scanf("%d", &l);
	int A[l];
	int q;
	int ch = 0;
	while(1){
		printf("\nChoose:\n1.PUSH\n2.POP\n3.PEEK\n4.I hate Stack\n >>");
		scanf("%d", &ch);

		if (ch == 4){
			break;
		}
			switch (ch) {
			case 1:
				printf("Push what?: ");
				int num;
				scanf("%d", &num);
				PUSH(A, num, l);
				break;
			case 2:
				q = POP(A, l);
				printf("%d has been popped\n", q);
				break;
			case 3:
				printf("%d is at the top", A[top]);
				break;
			default:
				printf("Yo!");
		}
	}
}*/
