#include <stdio.h>

int max(int n1, int n2) {
    if (n1 >= n2) return n1;
    else return n2;
}

void lcs(int n1, int n2, char str1[], char str2[]) {
    int dp[n1+1][n2+1];
    int i, j;

    for (i = 0; i <= n1; i++) {
        for (j = 0; j <= n2; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int length = dp[n1][n2];
    printf("\nThe length of the Longest Common Subsequence is: %d", length);

    char subseq[length+1];
    subseq[length] = '\0';

    i = n1, j = n2;
    while (i > 0 && j > 0) {
        if (str1[i-1] == str2[j-1]) {
            subseq[--length] = str1[i-1];
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("\nThe Longest Common Subsequence is: %s", subseq);
}

int main() {
    int n1, n2;
	printf("Enter the length of first string: ");
	scanf("%d",&n1);

	char str1[n1+1];
	printf("Enter the first string: ");
	scanf("%s", &str1);

	printf("\nEnter the length of second string: ");
	scanf("%d",&n2);

	char str2[n2+1];
	printf("Enter the second string: ");
	scanf("%s", &str2);

	lcs(n1, n2, str1, str2);

	return 0;
}
