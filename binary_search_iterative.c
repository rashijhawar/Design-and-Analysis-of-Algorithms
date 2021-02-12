/*
    Time Complexity:
        Worst case = O(log n)
        Average case = O(log n)
        Best case = O(1)
    Space Complexity = O(1)
*/

#include <stdio.h>

int binary_search_iterative(int a[], int n, int element) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {  // maybe low < high ?
        int mid = (low + high)/2;
        /*
            To avoid overflow, we can use:
            mid = low + (high - low)/2;
            (OR)
            mid = high - (high - low)/2;
        */

        if (element == a[mid])
            return mid;
        else if (element < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int a[50];
    int n;
    int element;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array in sorted order: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the value you want to search in the array: ");
    scanf("%d", &element);

    int result = binary_search_iterative(a, n, element);
    if (result != -1)
        printf("\n%d found at index %d.\n", element, result);
    else
        printf("\n%d not found in the array.\n", element);

    return 0;
}
