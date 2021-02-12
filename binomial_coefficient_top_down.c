#include <stdio.h>
#define N 50
#define R 50

int result[N][R] = {[0 ... N-1]{[0 ... R-1] = -1}};

int binomial_coefficient(int n, int r) {
    if (result[n][r] == -1) {
        if (n == r || r == 0)
            result[n][r] = 1;
        else
            result[n][r] = binomial_coefficient(n-1, r-1) + binomial_coefficient(n-1, r);
    }
    return result[n][r];
}

int main() {
    int n, r;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the value of r: ");
    scanf("%d", &r);

    printf("\nnCr = %dC%d = %d", n, r, binomial_coefficient(n, r));

    return 0;
}

