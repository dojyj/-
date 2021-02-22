#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    //brown = (yellow 가로 * 2) + (yellow 세로 * 2) + 4
    // i*i >= yellow 가 안되는 반례 (decrease 하며 비교할 때는 내림 계산이 필수..)
    // i == 7, yellow = 50 ===> 49 >= 50으로 돌아가지 않음, i >= yellow / i ===> 7 >= 7으로 돌아감 
    for(int i = yellow; i >= (yellow/i); i--){
        if (yellow % i != 0)
            continue;
        if (brown == ((i * 2) + ((yellow / i) * 2) + 4)){
            answer.push_back(i+2);
            answer.push_back(yellow / i + 2);
            break;
        }
    }
    
    return answer;
}