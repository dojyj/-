#include <iostream>
#include <string.h>
using namespace std;
 
int N;
int graph[1001][1001];
int degree[1001];

int check_graph()
{
	for(int i = 1; i <= N; i++){
		degree[i] /= 2;
		if (degree[i] % 2)
			return 1;
	}
	
	return 0;
}
 
void dfs(int node)
{
	for(int i = 1; i <= N; i++){
		while(graph[node][i]){
			--graph[node][i];
			--graph[i][node];
			dfs(i);
		}
	}
	
	printf("%d ", node);
}
int main() {
	scanf("%d\n", &N);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			scanf("%d ", &graph[i][j]);
			
			degree[i] += graph[i][j];
			degree[j] += graph[i][j];
		}
	}
 
	if (check_graph()){
		printf("-1");
		return 0;
	}
	dfs(1);
	return 0;
}