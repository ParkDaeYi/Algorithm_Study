#include <iostream>
#include <algorithm>
#include <stack>
#define MAX 1001
using namespace std;

class point {
public:
	int x, y, dx, dy, idx;
	point(int x = 0, int y = 0, int idx = 0) :x(x), y(y), idx(idx) {}
	bool operator < (const point& p) const {
		if (dy * p.dx != dx * p.dy) return dy * p.dx < dx * p.dy;
		return y == p.y ? x < p.x : y < p.y;
	}
}pos[MAX];
int n, sz, len, lev[MAX], h = 1;
bool used[MAX];

int ccw(point a, point b, point c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	sz = n;
	for (int i = 0, x, y; i < n; ++i) {
		cin >> x >> y;
		pos[i] = point(x, y, i);
	}
	while (sz > 2) {
		sort(pos, pos + sz);
		for (int i = 1; i < sz; ++i) pos[i].dx = pos[i].x - pos[0].x, pos[i].dy = pos[i].y - pos[0].y;
		sort(pos + 1, pos + sz);
		stack<int> convex;
		convex.push(0); convex.push(1);
		int next = 2;
		while (next < sz) {
			while (convex.size() > 1) {
				int second = convex.top(); convex.pop();
				int first = convex.top();
				if (ccw(pos[first], pos[second], pos[next]) > 0) {
					convex.push(second);
					break;
				}
			}
			convex.push(next++);
		}
		len = convex.size();
		if (len < 3) break;
		while (!convex.empty()) {
			used[convex.top()] = 1;
			lev[pos[convex.top()].idx] = h;
			convex.pop();
		}
		for (int i = 0, idx = 0; i < sz; ++i) {
			if (used[i]) continue;
			pos[idx] = pos[i];
			pos[idx].dx = pos[idx].dy = 0;
			idx++;
		}
		fill(used, used + sz, 0);
		sz -= len;
		len = 0;
		h++;
	}
	for (int i = 0; i < n; ++i) cout << lev[i] << ' ';
	return 0;
}