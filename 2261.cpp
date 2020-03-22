#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#define INF 100010
using namespace std;

/*
* set은 원소를 자동정렬 해주기 때문에
* 직접 class를 구현하여 y좌표를 기준으로 정렬해줌
*/
class pii {
public:
	int x, y;
	pii(){}
	pii(int x,int y):x(x),y(y){}
	bool operator<(const pii& p) const {
		if (y == p.y) return x < p.x;
		return y < p.y;
	}
};

// x좌표를 사용하여 가까운 점을 찾을거임
bool cmp(const pii& p1, const pii& p2) {
	return p1.x < p2.x;
}

int getDist(pii p1, pii p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int n, ans = 1e9 + 1;
pii pos[100000];
set<pii> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> pos[i].x >> pos[i].y;
	sort(pos, pos + n, cmp);
	for (int i = 0, e = 0; i < n; ++i) {
		for (int j = e; j < i; ++j) {
			// x 좌표의 제곱이 ans 보다 크면
			// y까지 볼 필요 없이 크다는 것을 알 수 있음
			// 시간을 절약하기 위해 set에서 제거 해줌
			if ((pos[i].x - pos[j].x) * (pos[i].x - pos[j].x) > ans) {
				s.erase(pos[j]);
				e++;
			}
			else break;
		}
		int cur_dist = (int)sqrt((double)ans) + 1;
		//set은 y 값을 기준으로 정렬하였기 때문에
		//x 값엔 INF를 넣음
		pii low(-INF, pos[i].y - cur_dist);
		pii high(INF, pos[i].y + cur_dist);
		//y 좌표 탐색
		auto left = s.lower_bound(low);
		auto right = s.upper_bound(high);
		for (auto itr = left; itr != right; itr++) ans = min(ans, getDist(*itr, pos[i]));
		s.insert(pos[i]);
	}
	cout << ans;
	return 0;
}