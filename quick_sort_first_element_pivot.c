/*
    Time Complexity:
        Worst case = O(n^2)
        Average case = O(n*log n)
        Best case = O((n*log n)
    Space Complexity = O(n)
*/

// FIRST ELEMENT PIVOT

#include <stdio.h>

int partition(int a[], int l, int r) {
    int pivot = l;
    int i = l;
    int j = r;
    int temp;

    while (i < j) {
        while (a[i] <= a[pivot] && i < j) i++;
        while (a[j] > a[pivot]) j--;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[pivot];
    a[pivot] = a[j];
    a[j] = temp;

    return j;
}

void quick_sort(int a[], int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quick_sort(a, l, p-1);
        quick_sort(a, p+1, r);
    }
}

int main() {
    int a[50], n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quick_sort(a, 0, n - 1);

    printf("\nThe sorted array is:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}




