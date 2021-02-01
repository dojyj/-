#include <iostream>
#include <string.h>
using namespace std;

int C;
int ddmg[101][101];
int check[101][101];

int jump(int size, int x, int y){
	// 1. base condition
    if (x > size - 1 || y > size - 1)
		return 0;
		
	if (ddmg[x][y] == 0)
		return 1;
	
    // 2. memoization
	int &ret = check[x][y];
	
	if (ret != -1)
		return ret;

    // 3. recursive call	
	ret = jump(size, x + ddmg[x][y], y) || jump(size, x, y + ddmg[x][y]);
	return ret;
}

int main() {
	scanf("%d\n", &C);
	for(int i = 0; i < C; i++){
		int n;
		
		memset(ddmg, -1, sizeof(ddmg));
		memset(check, -1, sizeof(ddmg));
		
		scanf("%d\n", &n);
		for(int x = 0; x < n; x++){
			for(int y = 0; y < n; y++){
				scanf("%d", &ddmg[x][y]);
			}
		}
		if (jump(n, 0, 0))
			printf("YES\n");
		else
			printf("NO\n");
		
	}
	return 0;
}