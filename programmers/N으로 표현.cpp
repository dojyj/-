#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int avail[5];
int answer = 9;
    
void dfs(int num ,int res, int N, int number){
    //printf("%d %d\n", num ,res);
    
    if (num > 8){
        return;
    }
    
    if (res == number){
        answer = min(answer, num);
        return;
    }
    
    int tmp_num = 0;
    for(int i = 0; i + num < 9; i++){
        tmp_num = tmp_num * 10 + N;
        
        dfs(num + 1 + i, res + tmp_num, N, number);
        dfs(num + 1 + i, res - tmp_num, N, number);
        dfs(num + 1 + i, res * tmp_num, N, number);
        dfs(num + 1 + i, res / tmp_num, N, number);
    }
}

int solution(int N, int number) {
    dfs(0, 0, N, number);
    //printf("%d\n", answer);
    
    if (answer > 8)
        return -1;
    else
        return answer;
}