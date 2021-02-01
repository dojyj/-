#include <iostream>
#include <limits.h>
#include <string.h>
using namespace std;

int N;
int dp[501][501];
pair<int, int> matrix[501];

int get_ans(int left, int right){
    // base condition
	if (left == right)
		return 0;
	
    // memoization
	int& ret = dp[left][right];
	if (ret != -1)
		return ret;
	
    // binary count
	ret = INT_MAX;
	for(int i = left; i < right; i++){
		ret = min(ret, get_ans(left, i) + get_ans(i+1, right) + matrix[left].first * matrix[i].second *matrix[right].second);
	}
	
	return ret;
}

int main() {
	scanf("%d\n", &N);
	for(int i = 0; i < N; i++){
		scanf("%d %d\n", &matrix[i].first, &matrix[i].second);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", get_ans(0, N - 1));
	return 0;
}