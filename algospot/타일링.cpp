#include <iostream>
#include <string.h>

using namespace std;

int M = 1000000007;
int C;
int dp[101];

// fibonacci
int main() {
	dp[0] = 1;
	dp[1] = 2;
	for(int i = 2; i < 101; i++){
		dp[i] = (dp[i-1] + dp[i-2]) % M;
	}
	
	scanf("%d\n", &C);
	for(int i = 0; i < C; i++){
		int n;
		scanf("%d\n", &n);
		printf("%d\n", dp[n - 1]);
	}
	return 0;
}