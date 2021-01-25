#include <iostream>
#include <vector>
using namespace std;

int T;
vector<int> coin;

int main() {
	scanf("%d\n", &T);
	while(T--){
		int N;
		coin.clear();
		scanf("%d\n", &N);
		for (int i = 0; i < N; i++){
			int tmp;
			scanf("%d ", &tmp);
			coin.push_back(tmp);
		}
		int price;
		scanf("%d\n", &price);
		int dp[10001] = {0, };	

		dp[0] = 1;
		
		for(int i = 0; i < N; i++){
			for (int j = coin[i]; j <= price; j++){
				dp[j] += dp[j - coin[i]]; 
			}
		}
		
		printf("%d\n", dp[price]);
	}
	return 0;
}