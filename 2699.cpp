#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

class point {
public:
	int x, y, nx, ny;
	point(int x = 0, int y = 0) :x(x), y(y), nx(0), ny(0) {}
	bool operator<(const point& p) const {
		if (ny * p.nx != nx * p.ny) return ny * p.nx > nx* p.ny;
		return y == p.y ? x < p.x : y > p.y;
	}
}pos[51];
int t, n;

int ccw(point a, point b, point c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0;i < n;++i) cin >> pos[i].x >> pos[i].y;
		sort(pos, pos + n);
		for (int i = 1;i < n;++i) pos[i].nx = pos[i].x - pos[0].x, pos[i].ny = pos[i].y - pos[0].y;
		sort(pos + 1, pos + n);
		vector<point> convex;
		for (int i = 0;i < n;++i) {
			while (convex.size() > 1 && ccw(convex[convex.size() - 2], convex.back(), pos[i]) >= 0)
				convex.pop_back();
			convex.push_back(pos[i]);
		}
		cout << convex.size() << '\n';
		for (point p : convex) cout << p.x << ' ' << p.y << '\n';
		fill(pos, pos + n, 0);
	}


	return 0;
}