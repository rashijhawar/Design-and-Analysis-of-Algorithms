/*
    Time Complexity:
        Worst case = O(n^2)
        Average case = O(n^2)
        Best case = O(n)
    Space Complexity = O(1)
*/

#include <stdio.h>

void insertion_sort_recursive(int a[], int n) {
    if (n <= 1) return;

    insertion_sort_recursive(a, n-1);

    int last = a[n-1];
    int j = n-2;

    while (j >= 0 && a[j] > last) {
        a[j+1] = a[j];
        j--;
    }
    a[j+1] = last;
}

int main() {
    int a[50], n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    insertion_sort_recursive(a, n);

    printf("\nThe sorted array is:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

