#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
	int x,y;
};

int dist(Point &p, Point &q){
	return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

// bool값을 입력받아 true이면 x기준 정렬, false이면 y기준 정렬
struct Comp {
    bool comp_in_x;
    Comp(bool b) : comp_in_x(b) {}
    bool operator()(Point &p, Point &q) {
        return (this->comp_in_x? p.x < q.x : p.y < q.y);
    }
};

int n;
vector<Point> Points;

int closest_pair(vector<Point>::iterator it, int n)
{
	// 비교할 점이 적게 남은 경우 Brute Force
	if (n == 2)
		return dist(it[0], it[1]);
	if (n == 3)
		return min({dist(it[0], it[1]), dist(it[1], it[2]), dist(it[2], it[0])});
	
	// 앞으로 봐야할 점들 중 가운데 x좌표를 line으로 지정	
	int line = (it[n/2 - 1].x + it[n/2].x) / 2;
	
	// 남은 점들 분할 정복
	int d = min(closest_pair(it, n/2), closest_pair(it + n/2, n - n/2));
	
	// y좌표 기준으로 정렬할 벡터 생성하고 공간 할당
	vector<Point> mid;
	mid.reserve(n);
	
	// 두 점의 x좌표간의 거리가 분할정복으로 구한 최소 거리인 d보다 작은 경우만 y좌표 비교
	for (int i = 0; i < n; i++){
		int t = line - it[i].x;
		if (t*t < d)
			mid.push_back(it[i]);
	}
	
	sort(mid.begin(), mid.end(), Comp(false));
	
	// mid안의 점들을 오름차순으로 비교하며 y좌표간의 거리가 d보다 작은 경우만 비교
	int size = mid.size();
	for(int i = 0; i < size; i++){
		for(int j = i+1; j < size && (mid[j].y - mid[i].y) * (mid[j].y - mid[i].y) < d; j++){
			d = min(d, dist(mid[i], mid[j]));
		}
	}
	
	return d;
}

int main() {
	scanf("%d\n", &n);
	for(int i = 0; i < n; i++){
		Point tmp;
		scanf("%d %d\n", &tmp.x, &tmp.y);
		Points.push_back(tmp);
	}
	
	sort(Points.begin(), Points.end(), Comp(true));
	printf("%d\n", closest_pair(Points.begin(), n));
	return 0;
}