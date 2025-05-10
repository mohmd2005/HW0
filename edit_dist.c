// 123456789
#include <stdio.h>
#include <string.h>
#define MAX_WORD_LEN 100
int edit_dist(char word1[], char word2[]);
int main() {
	char word1[MAX_WORD_LEN], word2[MAX_WORD_LEN];
	fgets(word1, MAX_WORD_LEN, stdin);
	word1[strlen(word1) -1] = '\0';
	fgets(word2, MAX_WORD_LEN, stdin);
	word2[strlen(word2) -1] = '\0';
	printf("%d\n", edit_dist(word1, word2));
	return (0);
}
int edit_dist(char word1[], char word2[]) {
    int m = strlen(word1);
    int n = strlen(word2);

    // Create a DP matrix of size (m+1) x (n+1)
    int *dp = (int *)malloc((m+1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)malloc((m+1) * sizeof(int));
    }

    // Initialize base cases
    for (int i = 0; i <= m; i++) dp[i][0] = i; // Delete all characters
    for (int j = 0; j <= n; j++) dp[0][j] = j; // Insert all characters

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1]; // No operation needed
            } else {
                int del = dp[i-1][j] + 1;  // Delete a character
                int ins = dp[i][j-1] + 1;  // Insert a character
                int sub = dp[i-1][j-1] + 1; // Substitute a character
                dp[i][j] = min(del, ins, sub);
            }
        }
    }

    int result = dp[m][n];

    for (int i = 0; i <= m; i++)
        free(dp[i]);
    free(dp);

    return result;
}
