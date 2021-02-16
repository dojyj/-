#include <iostream>
#include <algorithm>
using namespace std;
int N;
int answer = 0;
char board[51][51] = {0, };

int change(int x,int y, int newX, int newY){
	int temp;
	int verti = 1, hori = 1;
	
	swap(board[x][y], board[newX][newY]);

	// for(int i = 0; i < N; i++){
	// 	for(int j = 0; j < N; j++){
	// 		printf("%c ", bd[i][j]);
	// 	}printf("\n");
	// }printf("\n");
	
	char cur = board[x][y];
	int idx = x;
	
	while (idx-- > 0){
		if(board[idx][y] == cur)
			verti++;
		else
			break;
	}
	
	idx = x;
	while (++idx < N){
		if(board[idx][y] == cur)
			verti++;
		else
			break;
	}
	
	idx = y;
	while (idx-- > 0){
		if(board[x][idx] == cur)
			hori++;
		else
			break;
	}
	
	idx = y;
	while (++idx < N){
		if(board[x][idx] == cur)
			hori++;
		else
			break;
	}

	swap(board[x][y], board[newX][newY]);
	return max(verti, hori);
}

int getMax(int x, int y){
	int res1 = 0, res2 = 0, res3 = 0, res4 = 0;
	
	if (x > 0){
		res1 = change(x,y,x-1,y);
	}
	
	if (y != N - 1){
		res2 = change(x,y,x,y+1);
	}
	
	if (x != N - 1){
		res3 = change(x,y,x+1,y);
	}
	
	if (y > 0){
		res4 = change(x,y,x,y-1);
	}
	return max({res1, res2, res3, res4});	
}

int main() {

	scanf("%d\n", &N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if (j != N-1)	scanf("%c", &board[i][j]);
			else	scanf("%c\n", &board[i][j]);
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int temp = getMax(i, j);
	//			printf("%d %d => %d\n", i, j, temp);
			if (temp > answer){
				answer = temp;
			}
		}
	}
	
	printf("%d\n", answer);
	return 0;
}