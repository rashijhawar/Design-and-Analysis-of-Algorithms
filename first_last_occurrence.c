#include <stdio.h>
#include <stdbool.h>

int first_last_occurrence(int a[], int n, int element, bool first) {
    int low = 0;
    int high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high)/2;

        if (element == a[mid]) {
            result = mid;
            if (first)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else if (element < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return result;
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

    int first = first_last_occurrence(a, n, element, 1);
    int last = first_last_occurrence(a, n, element, 0);
    if (first != -1) {
        printf("\nFirst occurrence of %d at index: %d\n", element, first);
        printf("Last occurrence of %d at index: %d\n", element, last);
    }
    else
        printf("\n%d not found in the array.\n", element);

    return 0;
}
