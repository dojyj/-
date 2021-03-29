#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int from;
	int to;
	int value;
}edge;

vector<edge> edges;
int V, E;
int parent[10001];

int find(int x){
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y){
	x= find(x);
	y= find(y);
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
		if (find(edges[i].from) == find(edges[i].to)) continue; // 사이클 제거
		merge(edges[i].from, edges[i].to);
		ans += edges[i].value;
	}
	
	return ans;
}

int main() {
	scanf("%d %d\n", &V, &E);
	for(int i = 0; i < E; i++){
		edge e;
		scanf("%d %d %d\n", &e.from, &e.to, &e.value);
		edges.push_back(e);
	}
	
	for(int i = 1; i <= V; i++)
		parent[i] = i;
	printf("%d\n", kruskal());
	return 0;
}