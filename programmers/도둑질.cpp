#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(vector<int> money) {
    vector<int> start_at_first;
    vector<int> start_at_second;
    int N = money.size();
    
    start_at_first.push_back(money[0]);
    start_at_first.push_back(money[0]); // => 첫번째 집부터 시작하는 경우, 테스트 케이스가 10 0 2 100 2 등으로 오는경우, 최댓값을 100으로 출력, 때문에 2번째 집에도 값을 넣어주어야함.
    start_at_second.push_back(0);
    start_at_second.push_back(money[1]);
    
    // 도둑질 하는 경우를 크게 나누면 첫번째부터 털지, 두번째부터 털지로 나눌 수 있음. 그 외의 사항은 앞 두 사항에 포함됨. 따라서 이와 같이 문제 해결
    // 첫번째 집부터 도둑질 할 경우. 
    for(int i = 2; i < N-1; i++)
        start_at_first.push_back(max(start_at_first[i-1], start_at_first[i-2] + money[i]));
    
    // 두번째 집부터 도둑질 할 경우.
    for(int i = 2; i < N; i++)
        start_at_second.push_back(max(start_at_second[i-1], start_at_second[i-2] + money[i]));
    
    answer = max(start_at_first.back(), start_at_second.back());
    return answer;
}