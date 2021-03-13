#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int T,M,N,K;
int ground[51][51];
int answer;
queue<pair<int,int>> bfs;

int main() {
	scanf("%d", &T);
	while (T--){
		memset(ground, 0, sizeof(ground));
		answer = 0;
		
		scanf("%d %d %d\n", &M, &N, &K);
		for(int i = 0; i < K; i++){
			int a, b;
			scanf("%d %d\n", &a, &b);
			ground[a][b] = 1;
		}
	
		// for(int i = 0; i < N; i++){
		// 	for(int j = 0; j < M; j++){
		// 		printf("%d", ground[i][j]);
		// 	}printf("\n");
		// }
		
		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++){
				if (!ground[i][j])
					continue;
				else{
			//		printf("i : %d j : %d\n", i,j);
					answer++;
					bfs.push(make_pair(i, j));
					while(!bfs.empty()){
						int m = bfs.front().first;
						int n = bfs.front().second;
						bfs.pop();
						
						//printf("%d %d\n", m, n);
						
						ground[m][n] = 0;
						
						if (ground[m+1][n] && m <= M){
							bfs.push(make_pair(m+1, n));
							ground[m+1][n] = 0;
						}
						
						if (ground[m][n+1] && n <= N){
							bfs.push(make_pair(m, n+1));
							ground[m][n+1] = 0;
						}
						
						if (ground[m-1][n] && m > 0){
							bfs.push(make_pair(m-1, n));
							ground[m-1][n] = 0;
						}
						
						if (ground[m][n-1] && n > 0){
							bfs.push(make_pair(m, n-1));
							ground[m][n-1] = 0;
						}	
					}
				}
			}
		}
		printf("%d\n", answer);
	}
	return 0;
}