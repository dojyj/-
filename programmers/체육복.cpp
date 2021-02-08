#include <string>
#include <vector>
#include <string.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int arr[31] = {0,};
    
    for(int i = 0; i < n; i++)
        arr[i] = 1;
    
    for(int i = 0; i < lost.size(); i++)
        arr[lost[i] - 1]--;
    
    for(int i = 0; i < reserve.size(); i++)
        arr[reserve[i] - 1]++;
    
    for(int i = 0; i < n; i++){
        if (arr[i] == 2){
            if (arr[i-1] == 0 && i >= 1){
                arr[i-1]++;
                arr[i]--;
            }else if (arr[i+1] == 0){
                arr[i+1]++;
                arr[i]--;    
            }
        }else if (arr[i] == 0){
            if (arr[i] == 0){
                if (arr[i+1] == 2){
                    arr[i+1]--;
                    arr[i]++;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++){
    //  printf("%d\n", arr[i]);
        if (arr[i] > 0)
            answer++;
    }
    
    return answer;
}