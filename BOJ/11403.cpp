#include <iostream>
#define INF 987654321
using namespace std;

int N;
int G[101][101];

int main() {
	scanf("%d\n", &N);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			int temp;
			scanf("%d ", &temp);
			if (temp == 0)
				G[i][j] = INF;
			else
				G[i][j] = temp;
		}
	}
	
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if (G[i][j] > G[i][k] + G[k][j])
					G[i][j] = 1;
			}
		}
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if (G[i][j] == INF)
				printf("0 ");
			else
				printf("%d ", G[i][j]);
		}printf("\n");
	}
	return 0;
}