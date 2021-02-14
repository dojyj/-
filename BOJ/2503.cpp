#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int N;
vector<int> v;

int main() {
	// available num comb
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			for(int k = 1; k <= 9; k++){
				if (i == j || j == k || k == i)
					continue;
				else
					v.push_back(i*100+j*10+k);		
			}
		}
	}
	
	scanf("%d\n", &N);
	while(N--){
		int num, st, b;
		scanf("%d %d %d\n", &num, &st, &b);
		
		for(auto it = v.begin(); it != v.end();){
			char str1[10];
			char str2[10];
			int strike = 0, ball = 0;
			sprintf(str1, "%d", *it);
			sprintf(str2, "%d", num);
			
			// 스트라이크, 볼 count
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					if (str1[i] == str2[j]){
						if (i == j)
							strike++;
						else
							ball++;
					}
				}
			}
			
			// 현재 숫자와 동일한 스트라이크, 볼을 가지는 숫자 제외 전부 제거
			if (strike != st || ball != b){
				it = v.erase(it);
			}else
				it++;
		}
	}
	
	printf("%d\n", v.size());
	return 0;
}