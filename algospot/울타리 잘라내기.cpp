#include <iostream>
#include <vector>
using namespace std;

int C;

int solve(int left, int right, vector<int> &v)
{
	// base case
	if (left == right)
		return v[left];
	
	// mid, low, high 지정
	int mid = (left + right) / 2;
	int lo = mid;
	int hi = mid+1;
	
	// 분할정복으로 모든 울타리 비교 
	int ret = max(solve(left, lo, v), solve(hi, right, v));
	
	// 인접한 두 울타리 비교
	int min_h = min(v[lo], v[hi]); 
	ret = max(ret, 2 * min_h);
	
	// mid, mid + 1를 기점으로 근접한 울타리 중 큰 울타리 하나씩 붙이며 최대값 비교  
	while (lo > left || hi < right){
		if (hi < right && (lo == left || v[hi + 1] > v[lo - 1])){
			++hi;
			min_h = min(min_h, v[hi]);
		}else{
			--lo;
			min_h = min(min_h, v[lo]);
		}
		
		ret = max(ret, min_h * (hi - lo + 1));
	}
	
	return ret;
}	

int main() {
	scanf("%d\n", &C);
	for(int i = 0; i < C; i++){
		int N;
			
		vector<int> v;
		scanf("%d\n", &N);
		
		// input 
		for(int j = 0; j < N; j++){
			int tmp;
			scanf("%d ", &tmp);
			v.push_back(tmp);
		}
		
		// solve
		printf("%d\n", solve(0, N - 1, v));
	}
	return 0;
}