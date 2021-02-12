#include <stdio.h>

double fractionalKnapsack(int W, int wt[], int val[], int n){
    int arr[n][2], temp[2];

    for(int i=0; i<n; i++) {
        arr[i][0] = wt[i];
        arr[i][1] = val[i];
    }

    for(int i=0; i < n - 1; i++) {
        double r1 = (double)arr[i][1] / arr[i][0];
        double r2 = (double)arr[i+1][1] / arr[i+1][0];
        if (r1 < r2) {
            temp[0] = arr[i][0];
            temp[1] = arr[i][1];
            arr[i][0] = arr[i+1][0];
            arr[i][1] = arr[i+1][1];
            arr[i+1][0] = temp[0];
            arr[i+1][1] = temp[1];
        }
    }

    int curWeight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i][0] <= W) {
            curWeight += arr[i][0];
            finalvalue += arr[i][1];
            printf("\nWeight: %d    Value: %d", arr[i][0], arr[i][1]);
        } else {
            int remain = W - curWeight;
            double value = arr[i][1] * ((double) remain / arr[i][0]);
            finalvalue += value;
            printf("\nWeight: %d    Value: %lf", remain, value);
            break;
        }
    }

    return finalvalue;
}

int main() {
    int W, n, wt[30], val[30];

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Enter total number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of the items: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter the values of the items: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("\nMaximum value we can obtain: %f", fractionalKnapsack(W, wt, val, n));

    return 0;
}
