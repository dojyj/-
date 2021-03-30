#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
int parent[1001];

typedef struct{
	int from;
	int to;
	int value;
}edge;
vector<edge> edges;

int find(int x){
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	parent[y] = x;
}

bool func(const edge &a, const edge &b){
	return a.value < b.value;	
}

int kruskal()
{
	int ans = 0;
	
	sort(edges.begin(), edges.end(), func);
	for(int i = 0; i < edges.size(); i++){
		if (find(edges[i].from) == find(edges[i].to)) continue;
		merge(edges[i].from, edges[i].to);
		ans += edges[i].value;
	}
	return ans;
}

int main() {
	scanf("%d\n", &N);
	scanf("%d\n", &M);
	for(int i = 0; i < M; i++){
		edge e;
		scanf("%d %d %d\n", &e.from, &e.to, &e.value);
		edges.push_back(e);
	}	
	
	for(int i = 1; i <= N; i++)
		parent[i] = i;
	
	printf("%d\n", kruskal());
	return 0;
}