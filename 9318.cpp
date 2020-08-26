#include <iostream>
#include <cstdio>
#include <algorithm>
#define P 1000001
#define N 1001
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;

struct Point {
	int x, y1, y2, v;
	Point(int x = 0, int y1 = 0, int y2 = 0, int v = 0) :x(x), y1(y1), y2(y2), v(v) {}
	bool operator<(const Point& p) const {
		return x < p.x;
	}
}pos[N + N];
int t, n, seg[P * 4], cnt[P * 4];

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
	scanf("%d\n", &t);
	while (t--) {
		scanf("%d\n", &n);
		for (int i = 0, a, b, c, d;i < n;++i) {
			scanf("%d %d %d %d", &a, &b, &c, &d);
			pos[i] = Point(a, b, d - 1, 1);
			pos[n + i] = Point(c, b, d - 1, -1);
		}
		sort(pos, pos + n + n);
		ll ans = 0;
		for (int i = 0, prv;i < n + n;++i) {
			if (i) ans += 1LL * (pos[i].x - prv) * seg[1];
			udt(1, 0, P - 1, pos[i].y1, pos[i].y2, pos[i].v);
			prv = pos[i].x;
		}
		printf("%lld\n", ans);
	}
	return 0;
}