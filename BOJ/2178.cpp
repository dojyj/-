#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int N, M;
int maze[101][101] = {0, };
int answer = INT_MAX;
int udlr[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
queue<pair<int, int>> q;

void bfs()
{
	pair<int, int> cur;
	q.push(make_pair(0, 0));
	while(!q.empty()){
		cur = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int next_x = cur.first + udlr[i][0];
			int next_y = cur.second + udlr[i][1];
			
			if (next_x >= 0 && next_y >= 00 && next_x < N && next_y < M && maze[next_x][next_y] == 1){
				q.push(make_pair(next_x, next_y));
				maze[next_x][next_y] = maze[cur.first][cur.second] + 1;
			}
		}
	}
}

int main() {
	scanf("%d %d\n", &N, &M);
	for(int h = 0; h < N; h++){
		for(int w = 0; w < M; w++){
			char temp;
			scanf("%c", &temp);
			if (temp == '1')
				maze[h][w] = 1;
		}scanf("\n");
	}
	
	bfs();
	printf("%d\n", maze[N-1][M-1]);
	return 0;
}