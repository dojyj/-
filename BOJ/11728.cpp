#include <iostream>
#include <vector>
using namespace std;

int A, B;
vector<int> Av;
vector<int> Bv;

int main() {
	scanf("%d %d\n", &A, &B);
	for(int i = 0; i < A; i++){
		int temp;
		scanf("%d", &temp);
		Av.push_back(temp);
	}
	
	for(int i = 0; i < B; i++){
		int temp;
		scanf("%d", &temp);
		Bv.push_back(temp);
	}
	
	int idx_a = 0;
	int idx_b = 0;
	
	for(int i = 0; i < A + B; i++){
		if (Av[idx_a] > Bv[idx_b] && idx_b != B){
			printf("%d ", Bv[idx_b]);
			idx_b++;
		}else if (A != idx_a){
			printf("%d ", Av[idx_a]);
			idx_a++;
		}else{
			printf("%d ", Bv[idx_b]);
			idx_b++;
		}
	}
	return 0;
}