#include <iostream>
#include <algorithm>
using namespace std;

int N;
int maxDp[3];
int minDp[3];

int main() {
	scanf("%d\n", &N);
	scanf("%d %d %d\n", &maxDp[0], &maxDp[1], &maxDp[2]);
	minDp[0] = maxDp[0];
	minDp[1] = maxDp[1];
	minDp[2] = maxDp[2];
	
	for(int i = 1; i < N; i++){
		int input[3], temp0, temp2;
		scanf("%d %d %d\n", &input[0], &input[1], &input[2]);
	
		temp0 = maxDp[0]; temp2 = maxDp[2];
		maxDp[0] = max(maxDp[0], maxDp[1]) + input[0];
		maxDp[2] = max(maxDp[1], maxDp[2]) + input[2];
		maxDp[1] = max({temp0, maxDp[1], temp2}) + input[1];
		
		temp0 = minDp[0]; temp2 = minDp[2];
		minDp[0] = min(minDp[0], minDp[1]) + input[0];
		minDp[2] = min(minDp[1], minDp[2]) + input[2];
		minDp[1] = min({temp0, minDp[1], temp2}) + input[1];
	}
	
	printf("%d %d\n", max({maxDp[0],maxDp[1],maxDp[2]}), min({minDp[0],minDp[1],minDp[2]}));
	return 0;
}