#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int n, m, seg[1 << 17];
vector<pii> rain;

int lower_bd(int left, int right, int target) {	// 범위가 크기 때문에 Lower Bound 사용
	while (left < right) {
		int mid = (left + right) >> 1;
		if (rain[mid].first < target) left = mid + 1;
		else right = mid;
	}
	return right;
}

int query(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return seg[node];
	if (end < left || right < start) return 0;
	int mid = (start + end) >> 1;
	return max(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));	// 가장 큰 값 반환
}

int solve(int sz) {
	int y, x;
	cin >> y >> x;
	int py = lower_bd(0, rain.size(), y);
	int px = lower_bd(0, rain.size(), x);
	bool ychk = py < n && rain[py].first == y;	// 찾고자 하는 y년도가 맞는가
	bool xchk = px < n && rain[px].first == x;	// 찾고자 하는 x년도가 맞는가
	if (ychk && xchk && rain[px].second > rain[py].second) return 0;	// x가 y보다 클 경우
	int z = query(1, 0, sz - 1, lower_bd(0, rain.size(), y + 1), px - 1);	// y년도와 x년도 사이에서 가장 큰 강수량
	if (ychk && z >= rain[py].second) return 0;
	if (xchk && z >= rain[px].second) return 0;
	if (ychk && xchk && px - py == x - y) return 1;	// 모든 년도에 대한 정보가 있을 경우 true
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	const int sz = pow(2, (int)log2(n) + 1);
	for (int i = 0, x, y; i < n; ++i) {
		cin >> x >> y;
		rain.push_back({ x,y });	// 강수량 정보 입력
		seg[sz + i] = y;	// 세그먼트 리프 노드 추가
	}
	for (int i = sz - 1; i > 0; --i) seg[i] = max(seg[i * 2], seg[i * 2 + 1]);	// 갱신
	cin >> m;
	while (m--) {
		int ret = solve(sz);
		if (ret > 0) cout << "true\n";
		else if (!ret) cout << "false\n";
		else cout << "maybe\n";
	}
	return 0;
}