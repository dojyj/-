#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}
int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end(), cmp);
    int cam_idx = routes[0][1]; // 가장 빠르게 고속도로에서 벗어나는 차량의 고속도로에서 나간 지점
    for (auto i : routes){
        // 먼저 출입한 차량이 나가고 나서아 새로운 차량이 들어오면 새로운 카메라 필요. 
        if (cam_idx < i[0]){
            answer++;
            cam_idx = i[1];
        }
        // 먼저 들어온 차량이 나가기 전에 새로 들어온 차량이 나갈 예정이라면, 가장 빠르게 벗어나는 차량 update 
        if (cam_idx > i[1]){
            cam_idx = i[1];
        }
    }
        
    return answer;
}