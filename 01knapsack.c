#include <stdio.h>

int max(int, int);
void knapsack(int, int [], int [], int);

int main(){
    int length, totalWeight;
    int weight[10], profit[10];
    
    printf("Enter the number of items: ");
    scanf("%d", &length);
    
    printf("Enter the weight and profit of each item:-\n");
    for (int i=0; i<length; i++){
        printf("Item %d\n", i+1);
        printf("Weight: ");
        scanf("%d", &weight[i]);
        printf("Profit: ");
        scanf("%d", &profit[i]);
        printf("\n");
    }
    
    printf("Enter total weight permissible: ");
    scanf("%d", &totalWeight);
    
    knapsack(totalWeight, weight, profit, length);
}

int max(int a, int b){
    return (a>b) ? a : b;
}

void knapsack(int W, int weight[], int profit[], int n){
    int K[n+1][W+1];
    for (int i=0; i<=n; i++){
        for (int w=0; w<=W; w++){
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (weight[i-1] <= w)
                K[i][w] = max(K[i-1][w], profit[i-1] + K[i-1][w-weight[i-1]]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    int result = K[n][W];
    printf("The total profit made is %d\n", result);
    printf("The items used are as follows:-\n");
    printf("Item\tWeight\tProfit\n");
    int w = W;
    
    for (int i=n; i>0 && result>0; i--){
        if (result == K[i-1][w])
            continue;
        else{
            printf("%d\t%d\t%d\n", i, weight[i-1], profit[i-1]);
            result = result - profit[i-1];
            w = w - weight[i-1];
        }
    }
}
