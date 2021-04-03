#include <string>
#include <vector>

using namespace std;
int g[101][101] = {0, };

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(auto res : results)    g[res[0]][res[1]] = 1;
    
    // 플로이드-와샬
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if (g[i][k] && g[k][j])
                    g[i][j] = 1;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if (g[i][j] || g[j][i])
                cnt++;
        }
        if (cnt == n-1)
            answer++;
    }
    return answer;
}