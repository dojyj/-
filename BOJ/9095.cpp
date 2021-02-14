#include <iostream>
using namespace std;

int num[11];

int getAnswer(int num){
	if (num == 0)
		return 1;
	
	int res = 0;
	
	if (num - 1 >= 0)
		res += getAnswer(num - 1);
	if (num - 2 >= 0)
		res += getAnswer(num - 2);
	if (num - 3 >= 0)
		res += getAnswer(num - 3);
		
	return res;
}

int main() {
	// 1 ~ 10 까지의 숫자 가짓수 계산 (재귀)
	for(int i = 1; i < 11; i++){
		num[i] = getAnswer(i);
	}
	
	int N;
	scanf("%d\n", &N);
	while(N--){
		int temp;
		scanf("%d\n", &temp);
		printf("%d\n", num[temp]);
	}
	
	return 0;
}