#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;    
    sort(times.begin(), times.end());       // 시간순 정렬
    long long max_time = (long long)n * (long long)times.back();  // 최대 시간
    long long min_time = 1;                      // 최소 시간
    long long avg_time = 0;          // 현재 시간 (이분탐색, 초기값 : 최대 시간)
    
    while(min_time <= max_time){
        long long max_judge = 0;
        
        avg_time = (min_time + max_time) / 2;
        
        // 현재 시간에서 최대 검사할 수 있는 사람 수
        for(auto t : times){
            max_judge += avg_time / t;
        }
        
        printf("%d\n", max_judge);
        
        if (n > max_judge){      
            // 사람수가 최대 검사 수보다 크다면 시간 늘리기
            min_time = avg_time + 1;
        }else if (n <= max_judge) {
            // 사람수가 최대 검사 수보다 작다면 시간 줄이기
            answer = avg_time;
            max_time = avg_time - 1;
        }
    }
    return answer;
        
}