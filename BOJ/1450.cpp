#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long C;
vector<long long> thing, v1, v2;
long long answer = 0;

void dfs(int start, int end, long long sum, vector<long long> &v){
	if (sum > C)
		return;
	
	if (start == end){
		v.push_back(sum);
		return;
	}
		
	dfs(start + 1, end, sum, v);
	dfs(start + 1, end, sum + thing[start], v);
}

int main() {
	scanf("%d %lld\n", &N, &C);
	for(int i = 0; i < N; i++){
		long long temp;
		scanf("%lld ", &temp);
		thing.push_back(temp);	
	}
	
	// 가방을 2분할 하여 가능한 무게 합을 나누어 저장 2^30 -> 2^15 * 2
 	dfs(0, N/2, 0, v1);
	dfs(N/2, N, 0, v2);
	
	// 나온 합들을 오름차순으로 정렬
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	// for(int i = 0; i < v1.size(); i++){
	// 	printf("v1 : %d\n", v1[i]);
	// }
	
	// for(int i = 0; i < v2.size(); i++){
	// 	printf("v2 : %d\n", v2[i]);
	// }
	
	// two pointer
	for(int f = 0, b = v2.size() - 1; f < v1.size() && b >= 0; f++){
		while (v1[f] + v2[b] > C)	b--;
		answer += b + 1;
	}
	
	printf("%lld\n", answer);
	
	
	return 0;
}