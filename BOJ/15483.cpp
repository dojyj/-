#include <iostream>
#include <string.h>
#include <algorithm>

int dp[1001][1001] = {0, };
char str1[1001];
char str2[1001];

  
int main() {
	scanf("%s\n%s\n", str1, str2);
	
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	for (int i=0; i<=len1; i++)
    {
        for (int j=0; j<=len2; j++)
        {
            if (i==0)
                dp[i][j] = j;   
            else if (j==0)
                dp[i][j] = i;  
        	else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + std::min({dp[i][j-1],  // Insert 
                                   dp[i-1][j],  // Remove 
                                   dp[i-1][j-1]}); // Replace 
        }
    }

	printf("%d\n", dp[len1][len2]);
}