#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#define MAX 1001
using namespace std;
typedef long long int llt;

class point {
public:
	llt x, y, dx, dy;
	point(llt x = 0, llt y = 0) :x(x), y(y), dx(0), dy(0) {}
	bool operator<(const point& p) const {
		if (dy * p.dx != dx * p.dy) return dy * p.dx < dx * p.dy;
		return y == p.y ? x < p.x : y < p.y;
	}
}pos[MAX], pp;
int n, sz, len, h = 0;
bool used[MAX];

int ccw(point a, point b, point c) {
	llt tmp = (a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x);
	return tmp == 0 ? 0 : tmp > 0 ? 1 : -1;
}
bool make_prison();

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> pp.x >> pp.y;
	for (int i = 0; i < n; ++i) cin >> pos[i].x >> pos[i].y;
	sz = n;
	while (sz > 2) {
		sort(pos, pos + sz);
		for (int i = 1; i < sz; ++i) pos[i].dx = pos[i].x - pos[0].x, pos[i].dy = pos[i].y - pos[0].y;
		sort(pos + 1, pos + sz);
		if (!make_prison()) break;
		for (int i = 0, idx = 0; i < sz; ++i) {
			if (used[i]) continue;
			pos[idx++] = pos[i];
		}
		sz -= len;
		fill(used, used + sz, 0);
		len = 0;
		h++;
	}
	cout << h;
	return 0;
}

bool make_prison() {
	stack<int> convex;
	convex.push(0); convex.push(1);
	int next = 2;
	while (next < sz) {
		while (convex.size() > 1) {
			int op2 = convex.top(); convex.pop();
			int op1 = convex.top();
			if (ccw(pos[op1], pos[op2], pos[next]) > 0) {
				convex.push(op2);
				break;
			}
		}
		convex.push(next++);
	}
	len = convex.size();
	if (len < 3) return 0;
	vector<int> hull;
	while (!convex.empty()) {
		used[convex.top()] = 1;
		hull.push_back(convex.top());
		convex.pop();
	}
	int chk = ccw(pp, pos[hull[hull.size() - 1]], pos[hull[0]]);
	for (int i = 0; i < hull.size() - 1; ++i) {
		if (chk != ccw(pp, pos[hull[i]], pos[hull[i + 1]])) return 0;		
	}
	return 1;
}