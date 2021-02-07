#include <string>
#include <vector>
#include <string.h>

#define MOD 1000000007

using namespace std;

int minPath[101][101];
int pud[101][101] = {0, };

int solution(int m, int n, vector<vector<int>> puddles) {
    memset(minPath, 0, sizeof(minPath));
    
    //pud[x][y] => 해당 좌표에 웅덩이가 있으면 1, else 0
    for(int i = 0; i < puddles.size(); i++){
        pud[puddles[i][0]][puddles[i][1]] = 1;
    }
    
    // 처음값 / 물웅덩이는 0 / 현재 경로의 수는 왼쪽까지의 경로 + 위쪽까지의 경로 
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if (i == 1 && j == 1)
                minPath[i][j] = 1;
            else if (pud[i][j])
                minPath[i][j] = 0;
            else
                minPath[i][j] = (minPath[i-1][j] + minPath[i][j-1]) % MOD;
        }
    }
    return minPath[m][n];
}