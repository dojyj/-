#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int N = rocks.size();
    int l = 0, r = distance;
    deque<int> rock;
    
    // 돌 간의 거리를 구하기 위해 
    rock.assign(rocks.begin(), rocks.end());
    rock.push_front(l);
    rock.push_back(r);
    sort(rock.begin(), rock.end());
    
    while(l <= r){
        int cnt = 0;
        int d = (l + r) / 2;
        int pre_rock = rock[0];
        //printf("%d\n", d);
        
        // 지워야 될 돌 개수 구하기
        for(int i = 1; i < rock.size(); i++){
            if (d > rock[i] - pre_rock){
                cnt++;           
            }else{
                pre_rock = rock[i];
            }
        }
        
        if (cnt > n){
            // 바위를 덜 지워야 한다면 거리를 줄인다 
            r = d - 1;
        }else{
            // 바위를 더 지워야 한다면 거리를 늘린다
            if (d > answer)
                answer = d;
            l = d + 1;
        }
    }
    
    return answer;
}