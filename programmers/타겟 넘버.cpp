#include <string>
#include <vector>

using namespace std;

int answer = 0;
int t;
int N;

void dfs(int cnt, int cur, vector<int> numbers){
    //printf("%d %d %d\n", cnt, cur, answer);
    if (cnt == N-1){
        if (cur == t)   answer++;
        return;
    } 
    
    dfs(cnt + 1, cur + numbers[cnt+1], numbers);
    dfs(cnt + 1, cur - numbers[cnt+1], numbers);
}

int solution(vector<int> numbers, int target) { 
    t = target;
    N = numbers.size();
    dfs(0, numbers[0], numbers);
    dfs(0, -numbers[0], numbers);
    return answer;
}