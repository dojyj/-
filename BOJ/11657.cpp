#include <iostream>
#include <string.h>
#include <vector>
#include <tuple>
#define INF 987654321
using namespace std;

int N, M;
vector<tuple<int, int, int>> C;

int main() {
	scanf("%d %d\n", &N, &M);
	while(M--){
		int a,b,c;
		scanf("%d %d %d\n", &a, &b, &c);
		C.push_back(make_tuple(a,b,c));
	}
	
	long long bellman[501];
	for(int i = 0; i < 501; i++) bellman[i] = INF;
	bellman[1] = 0;
	
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < C.size(); j++){
			int here = get<0>(C[j]);
			int there = get<1>(C[j]);
			int cost = get<2>(C[j]);
			
			// printf("%d %d %d\n", here, there, cost);
			if (bellman[here] == INF)
				continue;
			
			if (bellman[there] > bellman[here] + cost)
				bellman[there] = bellman[here] + cost;
		}
	}
	
	// negative cycle 검증
	// 입력값에 따라 int 배열로 선언하면 cost overflow가 날 수 있음........ ㅠㅠ
	long long check[501] = {0, };
	memcpy(check, bellman, sizeof(bellman));
	
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < C.size(); j++){
			int here = get<0>(C[j]);
			int there = get<1>(C[j]);
			int cost = get<2>(C[j]);
	
			if (check[here] == INF)
				continue;
			
			if (check[there] > check[here] + cost)
				check[there] = check[here] + cost;
		}
	}
	
	bool flag = false;
	
	for(int i = 2; i <= N; i++)
		if (bellman[i] != check[i]) flag = true;
	
	if (flag)
		printf("-1\n");
	else{
		for(int i = 2; i <= N; i++){
			if (bellman[i] == INF)
				printf("-1\n");
			else
				printf("%lld\n", bellman[i]);
		}
	}
	// for(int i = 0; i < 501; i++) printf("%d\n", check[i]);
	return 0;
}