#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
#define N 100
using namespace std;

struct Point {
	int x, y1, y2, v;
	Point(int x = 0, int y1 = 0, int y2 = 0, int v = 0) :x(x), y1(y1), y2(y2), v(v) {}
	bool operator<(const Point& p) const {
		return x < p.x;
	}
}pos[N * 2];
int seg[N * 4], cnt[N * 4], ans;

void udt(int node, int start, int end, int left, int right, int val) {
	if (right < start || end < left) return;
	if (left <= start && end <= right) cnt[node] += val;
	else {
		int mid = (start + end) >> 1;
		udt(node * 2, start, mid, left, right, val);
		udt(node * 2 + 1, mid + 1, end, left, right, val);
	}
	if (cnt[node]) seg[node] = end - start + 1;
	else seg[node] = start == end ? 0 : seg[node * 2] + seg[node * 2 + 1];
}

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, c, d, idx = 0;
	while (cin >> a >> b >> c >> d) {
		pos[idx] = Point(a, b, d - 1, 1);
		pos[idx + 1] = Point(c, b, d - 1, -1);
		idx += 2;
	}
	sort(pos, pos + idx);
	for (int i = 0, prev;i < idx;++i) {
		if (i) ans += (pos[i].x - prev) * seg[1];
		udt(1, 0, N - 1, pos[i].y1, pos[i].y2, pos[i].v);
		prev = pos[i].x;
	}
	cout << ans;
	return 0;
}