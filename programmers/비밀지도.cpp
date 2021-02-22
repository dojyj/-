#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++){
        int ans = arr1[i] | arr2[i];
        string temp;
        
        for(int idx = 0; idx < n; idx++){
            if (ans % 2)
                temp += '1';
            else
                temp += '0';
            
            ans /= 2;
        }
        reverse(temp.begin(), temp.end());
        //printf("%s\n", temp.c_str());
        for(auto &i : temp){
            if (i == '1')
                i = '#';
            else if (i == '0')
                i = ' ';
        }
        answer.push_back(temp);
    }
    return answer;
}