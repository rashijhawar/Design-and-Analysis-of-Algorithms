/*
    Time Complexity:
        Worst case = O(n^2)
        Average case = O(n*log n)
        Best case = O((n*log n)
    Space Complexity = O(n)
*/

// LAST ELEMENT PIVOT

#include <stdio.h>

int partition(int a[], int l, int r) {
    int pivot = a[r];
    int i = l-1;
    int temp;

    for (int j = l; j <= r-1; j++) {
        if (a[j] < pivot) {
            i++;
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    temp = a[r];
    a[r] = a[i+1];
    a[i+1] = temp;

    return i+1;
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



