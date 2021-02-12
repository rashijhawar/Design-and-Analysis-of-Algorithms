/*
    Time Complexity:
        Worst case = O(log n)
        Average case = O(log n)
        Best case = O(1)
    Space Complexity = O(log n)  (Because of the recursion stack)
*/

#include <stdio.h>

int binary_search_recursive(int a[], int low, int high, int element) {
    if (low > high)
        return -1;

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
        binary_search_recursive(a, low, mid - 1, element);
    else
        binary_search_recursive(a, mid + 1, high, element);
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

    int result = binary_search_recursive(a, 0, n - 1, element);
    if (result != -1)
        printf("\n%d found at index %d.\n", element, result);
    else
        printf("\n%d not found in the array.\n", element);

    return 0;
}
