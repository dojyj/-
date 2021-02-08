#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//abcdefghijklm nopqrstuvwxyz b a a b b a a
int solution(string name) {
    int answer = 0;
    int len = name.length();
    int mid = len / 2;
    
    for(int i = 0; i < len; i++){
        if (name.at(i) > 'N')
            answer += 'Z' - name.at(i) + 1;
        else
            answer += name.at(i) - 'A';
    }
    
    int straight = 0;
    int reverse = 1;
    int warigari = 0;
    int front = len-1;
    int back = len-1;
    int back2 = len-1;
    
    for(int i = 1; i < len; i++){
        if (name.at(i) != 'A'){
            straight += i - straight;
            if (i <= mid)
                front = i;
        }
    }
    for(int i = len-1; i > 0; i--){
        if (name.at(i) != 'A'){
            reverse += (back - i);
            back = i;
            if (i >= mid)
                back2 = len -i;
        }
    }
    //printf("%d %d %d\n", front, back2, len);
    warigari = min((front * 2) + back2, front + (back2 * 2));
    //printf("%d %d %d\n", straight, reverse, warigari);
    return answer += min({straight, reverse, warigari});
}