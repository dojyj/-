#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1001][1001] = {0, };

int main() {
	char str1[1001];
	char str2[1001];
	
	scanf("%s\n%s", str1, str2);
	
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 1; i <= len1; i++){
		for (int j = 1; j <= len2; j++){
			dp[i][j] = max({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] + (str1[i-1] == str2[j - 1])});
		}
	}
	
	printf("%d", dp[len1][len2]);
	return 0;
}