#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sosu;
int num_cnt[10];

void get_sosu(int num){
    bool is_sosu;
    
    sosu.push_back(2);
    
    for(int i = 3; i <= num; i++){
        is_sosu = true;
        for(int j = 2; j * j <= i; j++){
            if (i % j == 0){
                is_sosu = false;
                break;
            }
        }
        
        if (is_sosu)
            sosu.push_back(i);
    }
}

int solution(string numbers) {
    int answer = 0;
    
    // 가능한 소수 완전탐색
    sort(numbers.begin(), numbers.end(), greater<int>());
    get_sosu(stoi(numbers));
    
    // string 분리해서 가지고 있는 종이조각 개수 세기
    for(auto i : numbers){
        num_cnt[i-'0']++;
    }
    
    // 범위내 소수에서 가지고 있는 종이조각으로 만들 수 있는 숫자 개수 세기
    for(auto i : sosu){
        int temp_cnt[10] = {0, };
        bool ans = true;
        string temp_str = to_string(i);
        
        for(auto c : temp_str){
            if(++temp_cnt[c-'0'] > num_cnt[c-'0']){
                ans = false;
                break;
            }
        }
        
        //printf("%d : %d\n", i, ans);
        
        if (ans)
            answer++;
    }
    return answer;
}