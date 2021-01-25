#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> A;
int dp[1001];
int answer = 1;

int main() {
	scanf("%d\n", &N);
	for(int i = 0; i < N; i++){
		int temp;
		scanf("%d ", &temp);
		A.push_back(temp);		
	}
	
	// 앞의 값들을 순회하며 현재 값이 부분 수열의 마지막 값이 될 수 있는 경우
	// 가장 긴 수열값을 dp에 저장
	// 모든 부분 수열의 길이는 1부터 시작
	for(int i = 0; i < N; i++){
		dp[i] = 1;
		for (int j = 0; j < i; j++){
			if (A[i] > A[j])
				dp[i] = max(dp[i], dp[j] + 1);
			answer = max(answer, dp[i]);	
		}
	}
	
	printf("%d\n", answer);
	return 0;
}