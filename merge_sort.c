/*
    Time Complexity:
        Worst case = O(n*log n)
        Average case = O(n*log n)
        Best case = O((n*log n)
    Space Complexity = O(n)
*/

#include <stdio.h>

void merge(int a[], int l, int m, int r) {
    int nl = m - l + 1;
    int nr = r - m;
    int left[nl], right[nr];

    int i, j, k;
    for(i = 0; i < nl; i++)
        left[i] = a[l + i];
    for(j = 0; j < nr; j++)
        right[j] = a[m + 1 + j];

    i = 0, j = 0, k = l;
    while(i < nl && j < nr) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < nl) {
        a[k] = left[i];
        i++; k++;
    }

    while(j < nr) {
        a[k] = right[j];
        j++; k++;
    }
}

void merge_sort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r)/2;
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int a[50], n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    merge_sort(a, 0, n - 1);

    printf("\nThe sorted array is:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}


