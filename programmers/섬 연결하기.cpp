#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

// 부모 노드를 찾는 함수. 재귀적으로 부모 노드를 찾아 리턴
int get_root(vector<int> &parent, int x){
    if (x == parent[x])
        return x;
    
    return parent[x] = get_root(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수.
// 항상 작은 부모노드에 합침
void union_parent(vector<int> &parent, int a, int b){
    a = get_root(parent, a);
    b = get_root(parent, b);
    if (a < b){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
}

// 같은 부모를 가지는지 확인
bool find_parent(vector<int> &parent, int a, int b)
{
    a = get_root(parent, a);
    b = get_root(parent, b);
    
    // 같으면 true, 다르면 false
    return (a == b);
}

bool cmp(vector<int> v1, vector<int> v2){
    return v1[2] < v2[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int size = costs.size();
    
    vector<int> parent(n);
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    sort(costs.begin(), costs.end(), cmp);
    for(auto& it:costs){
        int p1 = it[0];
        int p2 = it[1];
        int v = it[2];
       // printf("%d %d %d\n", p1, p2, v);
        
        if (!find_parent(parent, p1, p2)){
            answer += v;
            union_parent(parent, p1, p2);
        }
    }
    return answer;
}