#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 작업의 소요시간을 비교. a의 소요시간이 크다면 바꾼다 => 소요시간이 작은게 root => min heap
struct cmp{
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int N = jobs.size();
    int cur_time = 0;
    int idx = 0;
    int cnt = 0;
    
    priority_queue<vector<int>, vector<vector<int>>, cmp> ctl;
    
    sort(jobs.begin(), jobs.end()); // 먼저 시간 순으로 정렬

    while(idx < N || !ctl.empty()){
        // 현재 실행할 수 있는 모든 작업 컨트롤러에 넣기
        if (idx < N && cur_time >= jobs[idx][0]){
            ctl.push(jobs[idx++]);
            continue;
        }
        
        if (!ctl.empty()){
            // 컨트롤러가 비어있지 않다면 작업 수행
            cur_time += ctl.top()[1];
            answer += cur_time - ctl.top()[0];
            ctl.pop();
            cnt++;
        }else{
            // 컨트롤러가 비어있다면 다음 작업 가능시간으로 이동
            cur_time = jobs[idx][0];
        }
        
    }
    
    answer /= N;
    return answer;
}