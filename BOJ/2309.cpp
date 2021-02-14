#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int total = 0;
	for(int i = 0; i < 9; i++){
		int temp;
		scanf("%d\n", &temp);
		v.push_back(temp);
		total += temp;
	}
	
	sort(v.begin(), v.end());
	
	int idx1, idx2;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if (total - v[i] - v[j] == 100){
				idx1 = i;
				idx2 = j;
				break;
			}
		}
	}
	if (idx1 > idx2){
		v.erase(v.begin() + idx1);
		v.erase(v.begin() + idx2);
	}
	else{
		v.erase(v.begin() + idx2);
		v.erase(v.begin() + idx1);
	}
	
	for(auto i : v){
		printf("%d\n", i);
	}
	return 0;
}