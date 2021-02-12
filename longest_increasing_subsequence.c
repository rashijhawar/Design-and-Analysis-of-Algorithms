#include <stdio.h>

int max(int n1, int n2) {
    if (n1 >= n2) return n1;
    else return n2;
}

void lengths(int n, int arr[]) {
    int lengths[n], index[n];
    lengths[0] = 1;
    index[0] = 0;

    int i, j;
    for (i = 0; i < n; i++) {
        lengths[i] = 1;
        index[i] = 0;
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j] && lengths[i] < lengths[j]+1) {
                lengths[i] = lengths[j] + 1;
                index[i] = j;
            }
    }

    int max_index = 0;
    for (i = 0; i < n; i++) {
        if (lengths[i] >= lengths[max_index])
            max_index = i;
    }

    int length = lengths[max_index];
    printf("\nThe length of the Longest Increasing Subsequence is: %d", length);

    int lis[length+1];
    lis[length] = '\0';
    lis[--length] = arr[max_index];

    i = max_index;
    while (i > 0) {
        lis[--length] = arr[index[i]];
        i = index[i];
    }

    printf("\nThe Longest Increasing Subsequence is: ");
    for (i = 0; i < lengths[max_index]; i++)
        printf("%d ", lis[i]);
}

int main() {
    int n;
	printf("Enter the length of the array: ");
	scanf("%d",&n);

	int arr[n];
	printf("Enter the elements of the array: ");
	for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

	lengths(n, arr);

	return 0;
}

