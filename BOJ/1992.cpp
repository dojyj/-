#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
int video[65][65] = {0, };
string answer;

void compress(int x, int y, int size){
	int choice = video[x][y]; // 1로 압축될지 0으로 압축될지 첫번째 digit으로 정함.
	int res = true;
	
//	printf("%d %d %d\n", x, y, size);
	
//	printf("choice : %d, res : %d\n", choice, res);
	for (int i = x; i < x + size; i++){
		for (int j = y; j < y + size; j++){
			if (choice != video[i][j])
				res = false;
		}
	}
//	printf("choice : %d, res : %d\n\n", choice, res);
	if (res == true){
		// answer update && close parenthesis
		if (choice == 1){
			answer += '1';
		}else{
			answer += '0';
		}
	}else{
		// divide & conquer
		int mid = size / 2;
		answer += '(';
		compress(x, y, size / 2);
		compress(x, y + mid, size / 2);
		compress(x + mid, y, size / 2);
		compress(x + mid, y + mid, size / 2);
		answer += ')';
	}
}

int main() {
	// 입력받기
	scanf("%d\n", &N);
	for(int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			char c;
			if (j == N - 1)
				scanf("%c\n", &c);
			else
				scanf("%c", &c);
			if (c == '1')
				video[i][j] = 1;
		}
	}
	
	compress(0, 0, N);
	printf("%s\n", answer.c_str());
	return 0;
}