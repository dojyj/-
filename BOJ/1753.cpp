#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#define MAXV 20001
#define INF 987654321
using namespace std;

int V, E;
int startV;
vector<pair<int, int>> g[MAXV];

vector<int> dijkstra()
{
	vector<int> dist(V+1, INF);
	dist[startV] = 0;
	
	priority_queue<pair<int, int>> pq;
	
	pq.push(make_pair(0, startV));
	
	while (!pq.empty()){
		int cost = -pq.top().first;
		int cur = pq.top().second;
		
		pq.pop();
		
		if (dist[cur] < cost)
			continue;
		
		for(int i = 0; i < g[cur].size(); i++){
			int aim = g[cur][i].first;
			int nextDist = cost + g[cur][i].second;
			
			if (dist[aim] > nextDist){
				dist[aim] = nextDist;
				pq.push(make_pair(-nextDist, aim));
			}
		}
	}
	
	return dist;
}

int main() {
	scanf("%d %d\n", &V, &E);
	scanf("%d\n", &startV);

	while(E--){
		int u,v,w;
		scanf("%d %d %d\n", &u, &v, &w);
		g[u].push_back(make_pair(v,w));
	}
	
	vector<int> ans = dijkstra();
	
	for(int i = 1; i <= V; i++)
		ans[i] == INF ? printf("INF\n") : printf("%d\n", ans[i]);
		
	return 0;
}