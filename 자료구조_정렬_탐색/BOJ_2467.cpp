#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N;
vector<long long> v;
int front = 0;
int back;

int main() {
	scanf("%d\n", &N);
	for(int i = 0; i < N; i++){
		long long temp;
		scanf("%lld", &temp);
		v.push_back(temp);
	}
	back = N -1;
	
	long long attr_value = 2000000001;
	int ans_f = front;
	int ans_b = back;
	
	// 두 포인터가 만날 때 까지
	while (front != back){
		if (attr_value > abs(v[front] + v[back])){
			attr_value = abs(v[front] + v[back]);
			ans_f = front;
			ans_b = back;
			
			if (attr_value == 0)
				break;
		}
		
		if (abs(v[front]) > abs(v[back]))
			front++;
		else
			back--;
	}
	
	printf("%lld %lld\n", v[ans_f], v[ans_b]);
}