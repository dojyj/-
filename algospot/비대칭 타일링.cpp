#include <iostream>
#include <string.h>

using namespace std;

int M = 1000000007;
int C;
int dp[101]; // fibonacci
int sym[101]; // 대칭인 타일 
                // 홀수의 경우 ~ | ~ => (n/2)-1까지의 비대칭 타일 갯수만큼 대칭
                // 짝수의 경우 ~ ~ or ~ = ~ => n/2 + n/2-1 의 비대칭 타일 갯수만큼 대칭
int main() {
	dp[0] = 1;
	dp[1] = 2;
	sym[0] = 1;
	sym[1] = 2;
	int idx = 3;
	for(int i = 2; i < 101; i++){
		dp[i] = (dp[i-1] + dp[i-2]) % M;
		if (i & 1)
			sym[i] = (dp[i/2] + dp[(i / 2) - 1]) % M;
		else
			sym[i] = dp[(i / 2) - 1];
	}
	
	scanf("%d\n", &C);
	for(int i = 0; i < C; i++){
		int n;
		scanf("%d\n", &n);
		int ans = (dp[n-1] >= sym[n-1]) ? dp[n-1] - sym[n-1] : dp[n-1] - sym[n-1] + M;
		printf("%d\n", ans);
	}
	return 0;
}