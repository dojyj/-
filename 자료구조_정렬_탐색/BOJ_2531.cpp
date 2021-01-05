#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> v;	// 읽어갈 배열
int N, d, k ,c;
deque<int> dq;  // sliding window 배열
int dish[3001]; // 중복 체크
int dish_cnt = 0; // 현재 sliding window에서 먹을수 있는 종류
int max_dish = -1; 

int main() {
	scanf("%d %d %d %d\n", &N, &d, &k , &c);	
	
	// 입력받기
	for(int i = 0; i < N; i++){
		int temp;
		scanf("%d\n", &temp);
		v.push_back(temp);
	}
	
	dish[c]++; // 쿠폰으로 받은 음식은 먹었다 치기
	dish_cnt++;
	
	// window에 초기값 넣기
	for(int i; i < k; i++){
		dq.push_back(v[i]);
		if (dish[v[i]] == 0)
			dish_cnt++;
		dish[v[i]]++;
	}
	max_dish = dish_cnt;
	
	// deque에서 앞에값 빼고 새로운 접시는 뒤에 넣으면서 판단. 
	for (int i = k; i < N + k; i++){
		int idx;
		int value;
		
		if (i >= N){
			idx = i % N;
		}else
			idx = i;
		
		value = dq.front();
		dish[value]--;
		if (dish[value] == 0)
			dish_cnt--;
		dq.pop_front();
		
		value = v[idx];
		if (dish[value] == 0)
			dish_cnt++;	
		dish[value]++;
		dq.push_back(value);
		if (max_dish < dish_cnt)
			max_dish = dish_cnt;
	}
	
	printf("%d\n", max_dish);
	return 0;
}