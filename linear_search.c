/*
    Time Complexity:
        Worst case = O(n)
        Average case = O(n)
        Best case = O(1)
    Space Complexity = O(1)
*/

#include <stdio.h>

int linear_search(int a[], int n, int element) {
    for(int i = 0; i < n; i++)
        if (a[i] == element)
            return i;
    return -1;
}

int main() {
    int a[50];
    int n;
    int element;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the value you want to search in the array: ");
    scanf("%d", &element);

    int result = linear_search(a, n, element);
    if (result != -1)
        printf("\n%d found at index %d.\n", element, result);
    else
        printf("\n%d not found in the array.\n", element);

    return 0;
}
