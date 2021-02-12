/*
    Time Complexity:
        Worst case = O(n^2)
        Average case = O(n*log n)
        Best case = O((n*log n)
    Space Complexity = O(n)
*/

// RANDOMIZED QUICK SORT

#include <stdio.h>
#include <math.h>

/*
// LOMUTO PARTITION
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
*/
//HOARE PARTITION
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

int random_pivot(int a[], int l, int r) {
    int random = l + rand() % (r - l);

    int temp = a[random];
    a[random] = a[r];
    a[r] = temp;

    return partition(a, l, r);
}

void quick_sort(int a[], int l, int r) {
    if (l < r) {
        int p = random_pivot(a, l, r);
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




