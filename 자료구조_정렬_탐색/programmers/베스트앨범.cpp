#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, vector<pair<int,int>>> music;
unordered_map<string, int> genre_cnt;

//first : 실행 수, second : 고유번호
bool cmp(pair<int, int> p1, pair<int, int> p2){
        return p1.first > p2.first;
}

bool cnt_cmp(pair<string, int> p1, pair<string, int> p2){
    return p1.second < p2.second;    
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<string, int>> genre_cnt_v;
    
    // music => 장르별 각각의 곡 실행수 및 곡 보유번호
    // genre_cnt => 장르별 재생횟수 총합
    for (int i = 0; i < genres.size(); i++){
        music[genres[i]].push_back(make_pair(plays[i], i));
        genre_cnt[genres[i]] += plays[i];
    }
    
    // 해쉬에 저장되어있는 각 장르의 음악 목록들 오름차순으로 정렬, auto &를 활용해 주소참조 정렬
    for (auto &tmp : music){
        sort(tmp.second.begin(), tmp.second.end(), cmp);
        // for (int i = 0; i < tmp.second.size(); i++){
        //     printf("%d, %d\n", tmp.second[i], tmp.second[i].second);
        // }
    }
    
    // 장르별 재생횟수순으로 정렬.. unordered이기때문에 벡터로 옮겨서 정렬
    genre_cnt_v.assign(genre_cnt.begin(), genre_cnt.end());
    sort(genre_cnt_v.begin(), genre_cnt_v.end(), cnt_cmp);
    
    // answer 구하기
    int N = genre_cnt_v.size();
    for(int i = 0; i < N; i++){
        // 장르 구하기
        string g = "";
        g = genre_cnt_v.back().first;
        genre_cnt_v.pop_back();
        
        // 장르에서 곡 최대 두개 뽑기
        //printf("%s size : %d\n", g.c_str(), music[g].size());
        for(int j=0; (j < music[g].size() ) && (j < 2) ; j++){
            answer.push_back(music[g][j].second);      //노래 고유번호 answer에 삽입
        }
    
    }
    return answer;
}