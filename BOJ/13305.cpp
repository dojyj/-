#include <iostream>
#include <vector>
using namespace std;

int N;
long long min_price_sum;

vector<long long> len;
vector<long long> price;

int main() {
	min_price_sum = 0;
	scanf("%d\n", &N);
	for(int i = 0; i < N-1; i++){
		int tmp;
		scanf("%d ", &tmp);
		len.push_back(tmp);
	}
	for(int i = 0; i < N; i++){
		int tmp;
		scanf("%d ", &tmp);
		price.push_back(tmp);
	}
	
	int cur_price = price.front();
	
	for(int i = 0; i < N-1; i++){
		//printf("%d %d\n", cur_price, len[i]);
		min_price_sum += cur_price * len[i];
		if (cur_price > price[i+1]){
			cur_price = price[i+1];
		}
	}
	
	printf("%lld\n", min_price_sum);
	return 0;
}