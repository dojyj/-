#include <string>
#include <vector>

using namespace std;

int answer = 0;
int check[201] = {0, };

void dfs(int x, vector<vector<int>> computers){
    check[x] = 1;
    
    for(int i = 0; i < computers[x].size(); i++){
        if (i != x && computers[x][i] == 1 && !check[i]){
            dfs(i, computers);
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    for(int i = 0; i < n; i++){
        if (!check[i]){
            answer++;
            dfs(i, computers);
        }
    }
    
    return answer;
}