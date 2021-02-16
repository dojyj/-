#include <iostream>
#include <string>
#include <vector>

using namespace std;

int alpha[26] = {0, };
int N, K;
int answer = 0;

vector<string> word;

int wordcnt(){
	int cnt = 0;
	bool isRead;
	
    // word별로 탐색, 등록되지 않은 글자가 있으면 읽을 수 없음, cnt 불가
	for(int i = 0; i < word.size(); i++){
		isRead = true;
		for(auto c : word[i]){
			if (alpha[c - 'a'] == false){
				isRead = false;
				break;
			}
		}
		
		if (isRead)	
			cnt++;
	}
	
	return cnt;
}
void dfs(int idx, int cnt){
	// 남은 숫자만큼 단어를 등록했다면, 등록된 단어 기반으로 완전탐색, 배울수 있는 단어수 최대값 구하기 
    if (cnt == K){
		int tmpAns = wordcnt();
		answer = answer < tmpAns? tmpAns : answer;
		return;
	}
	
    // 26개의 알파벳 단어 dfs
	for (int i = idx; i < 26; i++){
		if (!alpha[i]){
			alpha[i] = true;
			dfs(i, cnt + 1);
			alpha[i] = false;
		}
	}
}
int main() {
	scanf("%d %d\n", &N, &K);
	for(int i = 0; i < N; i++){
		string str;
		cin >> str;
		word.push_back(str);
	}
	
	if (K < 5){
		printf("%d\n", answer);
		return 0;
	}else{
        // 필수적으로 들어가는 단어 등록
		alpha['a'-'a'] = true;
		alpha['c'-'a'] = true;
		alpha['i'-'a'] = true;
		alpha['n'-'a'] = true;
		alpha['t'-'a'] = true;
		K -= 5;
		
        // 탐색 
		dfs(0, 0);
		printf("%d\n", answer);
	}
	return 0;
}