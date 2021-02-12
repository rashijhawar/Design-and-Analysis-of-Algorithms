/*
    Time Complexity:
        Worst case = O(n^2)
        Average case = O(n^2)
        Best case = O(n)
    Space Complexity = O(1)
*/

#include <stdio.h>

void insertion_sort(int a[], int n) {
    int i, j;
    for(i = 1; i < n; i++) {
        int key = a[i];
        for(j = i-1; j >= 0; j--)
            if (a[j] > key)
                a[j+1] = a[j];
            else
                break;
        a[j+1] = key;
    }
}

int main() {
    int a[50], n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    insertion_sort(a, n);

    printf("\nThe sorted array is:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

