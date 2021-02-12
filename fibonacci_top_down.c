#include<stdio.h>
#define size 50

int result[size] = {[0 ... size-1] = -1};

int fibonacci(int n) {
    if(result[n] == -1) {
        if(n <= 1)
            result[n] = n;
        else
            result[n] = fibonacci(n-1) + fibonacci(n-2);
    }
    return result[n];
}

int main() {
    int n;
    printf("Enter n: ", &n);
    scanf("%d", &n);

    printf("fibonacci of %d: %d\n", n, fibonacci(n));

    return 0;
}
