#include<stdio.h>

int fibonacci(int n) {
    int fib[n+1], i;

    fib[0] = 0;
    fib[1] = 1;

    for(i = 2; i <= n; i++)
        fib[i] = fib[i-1] + fib[i-2];

    return fib[n];
}

int main() {
    int n;
    printf("Enter n: ", &n);
    scanf("%d", &n);

    printf("fibonacci of %d: %d\n", n, fibonacci(n));

    return 0;
}
