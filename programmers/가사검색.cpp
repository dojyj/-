#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    // 1. 글자 수로 정렬, 2. 알파벳 순으로 정렬
    if (a.size() != b.size())
        return a.size() < b.size();
    else
        return a < b;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<string> r_words(words);
    
    // ? 가 접두사로 올 경우를 대비 단어들이 역순으로 정렬되어있는 배열 만들기.
    for(int i = 0; i < r_words.size(); i++)
        reverse(r_words[i].begin(), r_words[i].end());
    
    // 이분탐색을 위해 모두 정렬
    sort(words.begin(), words.end(), cmp);
    sort(r_words.begin(), r_words.end(), cmp);
    
        // 쿼리 검사
    for(int i = 0; i < queries.size(); i++){
        // 이분탐색을 위해 left와 right 지정. left는 ?를 모두 a로, right는 ?를 모두 z로
        string left;
        string right;
        for(auto &tmp : queries[i]){
            if (tmp == '?'){
                left += 'a';
                right += 'z';
            }else{
                left += tmp;
                right += tmp;
            }
        }
        
        // ? 가 접두사로 주어진 경우, 뒤집어서 찾기
        if (queries[i].at(0) == '?'){
            reverse(left.begin(), left.end());
            reverse(right.begin(), right.end());
            int left_idx = lower_bound(r_words.begin(), r_words.end(), left, cmp) - r_words.begin();
            int right_idx = upper_bound(r_words.begin(), r_words.end(), right, cmp) - r_words.begin();
            answer.push_back(right_idx - left_idx);          
        }else{
            int left_idx = lower_bound(words.begin(), words.end(), left, cmp) - words.begin();
            int right_idx = upper_bound(words.begin(), words.end(), right, cmp) - words.begin();
            answer.push_back(right_idx - left_idx);              
        }    
    }
    
    return answer;
}