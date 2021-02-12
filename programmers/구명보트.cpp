#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    // two-pointer
    int f = 0;  //front
    int b = people.size() - 1;  //back
    
    while (f <= b){
        //printf("%d %d\n", people[f], people[b]);
        if (people[f] + people[b] > limit){
            b--;
            answer++;
        }else if (f == b){
            answer++;
            break;
        }else{
            f++;
            b--;
            answer++;
        }
    }
    return answer;
}