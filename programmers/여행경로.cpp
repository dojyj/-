#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool ticket_check[10001];
bool isFind = false;

void dfs(string start, vector<vector<string>> tickets, vector<string> &answer, int size)
{
    // 모든 티켓 다 사용했으면 정답. return
    if (size == tickets.size() + 1){
        isFind = true;
        //printf("find answer!\n");
        return;
    }
    vector<pair<string,int>> avail_arrive;
    
    // 현재 공항에서 갈 수 있는 공항들 찾아 저장
    for(int i = 0; i < tickets.size(); i++){
        // 사용한 티켓이면 건너뜀
        if (ticket_check[i])
            continue;
        if (tickets[i][0] == start){
            avail_arrive.push_back(make_pair(tickets[i][1], i));
        }
    }
    
    // 갈 수 있는 공항이 없으면 return
    if (avail_arrive.empty()){
        //printf("there is no airport\n");
        return;
    }
        
    
    // 알파벳 순으로 정렬
    sort(avail_arrive.begin(), avail_arrive.end());
    
    for(auto airport : avail_arrive){
        if(isFind)
            break;
        answer.push_back(airport.first);
        ticket_check[airport.second] = 1;
        dfs(airport.first, tickets, answer, size + 1);
        if (!isFind){
            answer.pop_back();
            ticket_check[airport.second] = 0;
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    answer.push_back("ICN");
    dfs("ICN", tickets, answer, 1);
    return answer;
}