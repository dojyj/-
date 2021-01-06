#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<long> x;

long max_d = -1;
		
int main() {
	// 입력
	scanf("%d %d\n", &N, &C);
	for(int i = 0; i < N; i++){
		long temp;
		scanf("%ld\n", &temp);
		x.push_back(temp);
	}
	
	// 정렬
	sort(x.begin(), x.end());
	
	// 좌표거리로 이진탐색
	long min_x = 1;
	long max_x = x.back();
	
	// 한번에 뛰어넘는 거리를 탐색하여 설치 할 수 있는 최대 공유기수를 구함. 
	while (min_x <= max_x){
		//printf("%d , %d\n", min_x, max_x);
		long avg_x = (min_x + max_x) / 2;
		long modem = x.front();
		int cnt = 1;
	
		// 현재 거리로 세울 수 있는 최대 공유기 숫자
		for (auto x_p : x){
			if (x_p - modem >= avg_x){
				modem = x_p;
				cnt++;
			}
		}
		
		//printf("avg : %d, cnt : %d\n", avg_x, cnt);
		// 세울 수 있는 공유기 수에 따라 거리 조절
		if (cnt >= C){
			if (max_d < avg_x)	// 구한 거리가 지금까지 구한 최댓값보다 크다면 swap
				max_d = avg_x;
			min_x = avg_x + 1;
		}else{
			max_x = avg_x - 1;
		}
	}
	
	printf("%ld\n", max_d);
	return 0;
}