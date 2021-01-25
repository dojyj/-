#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
deque<int> dq;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for(int i = 0; i < operations.size(); i++){
        // 문자열 처리
        auto cmd = operations[i].at(0);
        int num = stoi(operations[i].substr(2, operations[i].size()));
        
        if(cmd == 'I'){
            // deque에 넣고 오름차순으로 정렬
            dq.push_back(num);
            sort(dq.begin(), dq.end());
        }else if (cmd == 'D'){  
            // 비어있다면 cmd 무시
            if (dq.empty())
                continue;
            
            // 최대값 최소값 처리
            if (num == -1){
                dq.pop_front();
            }else if (num == 1){
                dq.pop_back();
            }
        }
    }
    
    // 정답 구하기
    if (!dq.empty()){
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }else{
        answer.push_back(0);
        answer.push_back(0);
    }
        
    return answer;
}