#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int danzi_num = 0;
vector<int> house_cnt;
int N;
int zido[26][26] = {0, };
int udlr[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<pair<int, int>> q;

void bfs(int x, int y){
	int cnt = 0;
	pair<int, int> cur;
	
	q.push(make_pair(x, y));
	zido[x][y] = 0;
	
	while(!q.empty()){
		cur = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int next_x = cur.first + udlr[i][0];
			int next_y = cur.second + udlr[i][1];
			
			if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < N && zido[next_x][next_y] == 1){
				q.push(make_pair(next_x, next_y));
				zido[next_x][next_y] = 0;
			}
		}
		//printf("%d %d\n", cur.first, cur.second);
		cnt++;
	}
	house_cnt.push_back(cnt);
}

int main() {
	scanf("%d\n", &N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			char temp;
			scanf("%c", &temp);
			if (temp == '1')
				zido[i][j] = 1;
		}scanf("\n");
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if (zido[i][j] == 1){
				danzi_num++;
				bfs(i, j);
			}
		}
	}
	
	printf("%d\n", danzi_num);
	sort(house_cnt.begin(), house_cnt.end());
	for(auto i : house_cnt)
		printf("%d\n", i);
	return 0;
}