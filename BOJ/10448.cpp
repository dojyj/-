#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<int> Tn;
int num[1001];
int N;

int main() {
	int i = 1;
	int res = 0;
	memset(num, -1, sizeof(num));
	
	// 삼각수 구하기
	while(res + i <= 1000){
		res += i;
		Tn.push_back(res);
		i++;
	}
	
	// 삼각수 3가지 숫자로 만들수 있는 값들 구하여 색칠
	for(int i = 0; i < Tn.size(); i++){
		for(int j = 0; j < Tn.size(); j++){
			for(int k = 0; k < Tn.size(); k++){
				int n = Tn[i] + Tn[j] + Tn[k];
				if (n > 1000)
					continue;
				else
					num[n] = 1;
			}
		}
	}
	
	// 판단
	scanf("%d\n", &N);
	while(N--){
		int temp;
		scanf("%d\n", &temp);
		if (num[temp] == 1)
			printf("%d\n", 1);
		else
			printf("%d\n", 0);
	}
	return 0;
}