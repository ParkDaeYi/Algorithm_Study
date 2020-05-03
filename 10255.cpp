#include <iostream>
#define INF 4
using namespace std;

struct point {
	int x, y;
	point(int x = 0, int y = 0) :x(x), y(y) {}
	bool operator==(const point& p) const {
		return x == p.x && y == p.y;
	}
	bool operator<(const point& p) const {
		return y == p.y ? x < p.x : y < p.y;
	}
};
int t;

int ccw(point a, point b, point c) {
	int tmp = a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
	return tmp == 0 ? 0 : tmp > 0 ? 1 : -1;
}

int sementIntersects(point a, point b, point c, point d) {
	if (!ccw(a, b, c) && !ccw(a, b, d)) {
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		if (b < c || d < a) return 0;
		else if (b == c || d == a) return 1;
		else return INF;
	}
	else {
		int ab = ccw(a, b, c) * ccw(a, b, d);
		int cd = ccw(c, d, a) * ccw(c, d, b);
		return ab <= 0 && cd <= 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		point vt[4], line[2];
		for (int i = 0; i < 3; i += 2) cin >> vt[i].x >> vt[i].y;
		vt[1].x = vt[2].x; vt[1].y = vt[0].y;
		vt[3].x = vt[0].x; vt[3].y = vt[2].y;
		cin >> line[0].x >> line[0].y >> line[1].x >> line[1].y;
		int ans = 0;
		for (int i = 0; i < 4; ++i) {
			point a = line[0], b = line[1], c = vt[i], d = vt[(i + 1) % 4];
			ans += sementIntersects(a, b, c, d);
			if (ans >= INF) {
				ans = INF;
				break;
			}
			if (sementIntersects(a, b, c, c)) ans--;
		}
		cout << ans << '\n';
	}
	return 0;
}