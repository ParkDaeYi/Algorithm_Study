#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 2001
using namespace std;
typedef long long int llt;
class point {
public:
	llt x, y, dx, dy, idx;
	point(llt x = 0, llt y = 0, llt idx = 0) : x(x), y(y), idx(idx), dx(0), dy(0) {}
	bool operator <(const point& p) const {
		if (dy * p.dx != dx * p.dy) return dy * p.dx < dx* p.dy;
		return x == p.x ? y < p.y : x < p.x;
	}
};
int t, n, m;

llt ccw(point a, point b) {
	return a.x * b.y - a.y * b.x;
}

llt ccw(point a, point b, point c) {
	return ccw(point(b.x - a.x, b.y - a.y), point(c.x - a.x, c.y - a.y));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		point pos[MAX_N];
		vector<point> convex;
		cin >> n;
		for (int i = 0;i < n;++i) cin >> pos[i].x >> pos[i].y, pos[i].idx = i;
		for (int i = 1;i < n;++i) {
			if (pos[i] < pos[0]) swap(pos[i], pos[0]);
		}
		for (int i = 1;i < n;++i) pos[i].dx = pos[i].x - pos[0].x, pos[i].dy = pos[i].y - pos[0].y;
		sort(pos + 1, pos + n);
		int pt = n - 1;
		for (;pt >= 1;pt--) {
			if (ccw(pos[0], pos[pt], pos[pt - 1])) break;
		}
		reverse(pos + pt, pos + n);
		for (int i = 0;i < n;++i) cout << pos[i].idx << ' '; cout << '\n';
	}
	return 0;
}