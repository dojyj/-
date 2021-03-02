#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define ANSWER_INIT 100

bool visited[51];
int answer = ANSWER_INIT;
    
int diff(string str1, string str2){
    int cnt = 0;
    for(int i = 0; i < str1.size(); i++){
        if (str1[i] != str2[i])
            cnt++;
    }    
    return cnt;
}

void dfs(string word, string target, vector<string> words, int depth)
{
    printf("%d : %s\n", depth, word.c_str());
    for(int i = 0; i < words.size(); i++){
        if (visited[i])
            continue;
        if (diff(word, words[i]) > 1)
            continue;
        //printf("%s %s %d\n", word.c_str(), words[i].c_str(), diff(word, words[i]));
        if (target == words[i])
            answer = min(answer, depth);
        visited[i] = true;
        dfs(words[i], target, words, depth + 1);
        visited[i] = false;
    }           
    return;
}

int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) != words.end())
        dfs(begin, target, words, 1);
    else
        return 0;
    
    if (answer == ANSWER_INIT)
        return 0;
    
    return answer;
}