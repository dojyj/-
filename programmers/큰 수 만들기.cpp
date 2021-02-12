#include <string>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    // 제거한 문자열 길이만큼 loop
    for(int i = 0, idx = -1; i < number.length() - k; i++){
        char max = 0;
        // init. 정답이 될 수 있는 범위안에서 최댓값 구하여 answer append
        // 초기 최대값이 정해졌다면 idx 1씩 늘려가며 각 자릿수의 최댓값을 구한다
        for(int j = idx + 1; j <= k + i; j++){
            if (max < number[j]){
                idx = j;
                max = number[j];
            }
        }
        answer += max;
    }
    return answer;
}