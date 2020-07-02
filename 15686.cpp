#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int n, m, ans = 1e9;
vector<pii> h, c;	// h: 집, c: 치킨집
bool visit[14];

int dist(pii p1,pii p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void backtracking(int idx, int cnt) {
	if (cnt == m) {
		int ret = 0;
		for (int i = 0; i < h.size(); ++i) {
			int d = 1e9;
			for (int j = 0; j < c.size(); ++j) {
				if (visit[j]) d = min(d, dist(h[i], c[j]));	// 선택된 치킨집만 거리 계산
			}
			ret += d;
		}
		ans = min(ans, ret);
		return;
	}

	if (idx == c.size()) return;	// idx는 현재 치킨집 갯수를 넘으면 안됨
	visit[idx] = 1;
	backtracking(idx + 1, cnt + 1);	// 선택 cnt + 1
	visit[idx] = 0;
	backtracking(idx + 1, cnt);	// 선택 안함
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) 
		for (int j = 0, x; j < n; ++j) {
			cin >> x;
			if (x == 1) h.push_back({ i,j });	// 집 정보
			else if (x == 2) c.push_back({ i,j });	// 치킨집 정보
		}
	
	backtracking(0, 0);
	cout << ans;

	return 0;
}