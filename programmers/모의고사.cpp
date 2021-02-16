#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int p1[5] = {1, 2, 3, 4, 5};
int p2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int p3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int N = answers.size();
    int is1 = 0, is2 = 0, is3 = 0;
    
    for(int i = 0; i < N; i++){
        if (answers[i] == p1[i%5])
            is1++;
        if (answers[i] == p2[i%8])
            is2++;
        if (answers[i] == p3[i%10])
            is3++;
    }
    
    int ans = max({is1, is2, is3});
    if (is1 == ans)     answer.push_back(1);
    if (is2 == ans)     answer.push_back(2);
    if (is3 == ans)     answer.push_back(3);
    return answer;
}