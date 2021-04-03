#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321

using namespace std;
int check[20001] = {0, };
int dist[20001] = {0, };
queue<int> q;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> lines(n+1);
    
    for(auto e : edge){
        lines[e[0]].push_back(e[1]);
        lines[e[1]].push_back(e[0]);
    }
    
    q.push(1);
    check[1] = true;
        
    while(!q.empty()){
        int from = q.front();
        q.pop();
        
        for(int i = 0; i < lines[from].size(); i++){
            int to = lines[from][i];
            if (check[to]) continue;
            check[to] = true;
            q.push(to);
            dist[to] = dist[from] + 1;    
        }
    }
    
    int max = -1;
    for (int i = 1; i <= n; i++){
        if (dist[i] > max){
            max = dist[i];
            answer = 1;
        }else if (dist[i] == max)
            answer++;
    }
    
    return answer;
}