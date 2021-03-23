#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <algorithm>
using namespace std;

/*
	#코사라주 알고리즘 활용 SCC 풀이
	=> dfs를 2번 사용하여 O(V+E)만에 SCC요소를 구하는 알고리즘
	1. 정방향그래프를 dfs를 수행하며 끝나는 순서대로 스택에 삽입
	2. 스택에서 pop하는 순서대로 역방향 dfs를 수행
	3. 역방향 dfs 한번 수행에 탐색되는 모든 정점을 같은 SCC로 묶음.
*/
int V, E;
int visited[10001] = {0, };
int scc_idx = 0;

vector<vector<int>> scc;
vector<vector<int>> vt;
vector<vector<int>> rvt;

stack<int> s;

void get_scc(int v, int c){
	visited[v] = true;
	scc[c].push_back(v);
	for(int next : rvt[v]){
		if (visited[next])
			continue;
		get_scc(next, c);
	}
}
void dfs(int v){
	visited[v] = true;
	for(int next : vt[v]){
		if (visited[next])
			continue;
		dfs(next);
	}
	s.push(v);
}

int main() {
	scanf("%d %d\n", &V, &E);
	
	vt.resize(V+1);
	rvt.resize(V+1);
	
	while(E--){
		int A, B;
		scanf("%d %d\n", &A, &B);
		vt[A].push_back(B);
		rvt[B].push_back(A);
	}
	
	// 1. 정방향 dfs
	for(int i = 1; i <= V; i++){
		if (visited[i])
			continue;
		dfs(i);
	}
	
	memset(visited, 0, sizeof(visited));
	
	// 2. 역방향 dfs
	while(!s.empty()){
		int v = s.top();
		s.pop();
		if (visited[v])
			continue;
		scc.resize(++scc_idx);
		// 3. 한번에 수행되는 모든 정점을 SCC로 묶음
		get_scc(v, scc_idx - 1);
	}
	
	int size = scc.size();
	for(int i = 0; i < size; i++)
		sort(scc[i].begin(), scc[i].end());
	sort(scc.begin(), scc.end());
	
	printf("%d\n", size);
	for(int i = 0; i < size; i++){
		for(int ans : scc[i])
			printf("%d ", ans);
		printf("-1\n");
	}
	
	return 0;
}