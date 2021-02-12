#include <stdio.h>

int min(int n1, int n2) {
    return (n1 < n2) ? n1 : n2;
}

void binomial_coefficient(int n, int r) {
    int dp[n+1][r+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, r); j++) {
            if (j == 0 || i == j)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    printf("nCr = %dC%d = %d", n, r, dp[n][r]);
}

int main() {
    int n, r;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the value of r: ");
    scanf("%d", &r);

    binomial_coefficient(n, r);

    return 0;
}
