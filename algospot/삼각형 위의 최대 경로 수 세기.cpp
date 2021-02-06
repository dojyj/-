#include <iostream>
#include <string.h>
using namespace std;

int C, n;
int Tri[101][101];
int MaxP[101][101];
int cnt[101][101];

// 사용 전역변수 초기화
void init(){
	memset(Tri, -1, sizeof(Tri));
	memset(MaxP, -1, sizeof(MaxP));
	memset(cnt, -1, sizeof(cnt));
	return;
}

// 각 정점에서 이동할 수 있는 최대 경로 구하기
void get_path(int x, int y)
{
	if (x == n)
		return;
	
	int &ret = MaxP[x][y];
	
	if (ret != -1)
		return;
	
	get_path(x+1, y);
	get_path(x+1, y+1);
	
	if (x == n - 1)
		ret = Tri[x][y];
	else
		ret = Tri[x][y] + max(MaxP[x+1][y], MaxP[x+1][y+1]);

	return;
}

// 중복되는 최대 경로의 수 세기
int get_path_cnt(int x, int y){
	if (x == n - 1)
		return 1;
	
	int &ret = cnt[x][y];
	
	if (ret != -1)
		return ret;
	
	ret = 0;
	if (MaxP[x+1][y] == MaxP[x+1][y+1])
		return ret = get_path_cnt(x+1, y) + get_path_cnt(x+1, y+1);
	else if (MaxP[x+1][y] > MaxP[x+1][y+1])
		return ret = get_path_cnt(x+1, y);
	else
		return ret = get_path_cnt(x+1, y+1);
}

int main() {
	scanf("%d\n", &C);
	while(C--){
		init();
		scanf("%d\n", &n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < i + 1; j++){
				scanf("%d ", &Tri[i][j]);
			}
		}
		get_path(0,0);
		// for(int i = 0; i < n; i++)
		// {
		// 	for(int j = 0; j < n; j++)
		// 		printf("%d ", MaxP[i][j]);
		// 	printf("\n");
		// }
		printf("%d\n", get_path_cnt(0, 0));
	}
	return 0;
}