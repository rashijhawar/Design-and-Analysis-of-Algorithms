/*
    Time Complexity:
        Worst case = O(n^2)
        Average case = O(n^2)
        Best case = O(n^2)
    Space Complexity = O(1)
*/

#include <stdio.h>

void selection_sort(int a[], int n) {
    int i,j, min, temp;
    for(i = 0; i < n-1; i++) {
       min = i;
       for(j = i+1; j < n; j++)
           if (a[j] < a[min])
                min = j;
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
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

    selection_sort(a, n);

    printf("\nThe sorted array is:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

