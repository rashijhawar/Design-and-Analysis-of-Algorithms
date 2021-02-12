/*
    Time Complexity:
        Worst case = O(n^2)
        Average case = O(n^2)
        Best case = O(n)
    Space Complexity = O(1)
*/

#include <stdio.h>

void bubble_sort(int a[], int n) {
    int temp;
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++) {
            if (a[j+1] < a[j]) {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
}

int main() {
    int a[50];
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    bubble_sort(a, n);

    printf("\nThe sorted array is:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
