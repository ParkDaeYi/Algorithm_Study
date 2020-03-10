#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000
#define MOD 100
using namespace std;

class info {
public:
	int x, y, p, q;
	info(int x = 0, int y = 0) :x(x), y(y), p(0), q(0) {}
}pos[MAX];
int n;
vector<info> convex;

bool cmp(const info& a, const info& b) {
	if (a.q * b.p != a.p * b.q) return a.q * b.p < a.p * b.q;
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

int ccw(info a, info b, info c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> pos[i].x >> pos[i].y;

	}
	sort(pos, pos + n, cmp);
	for (int i = 1; i < n; ++i) pos[i].p = pos[i].x - pos[0].x, pos[i].q = pos[i].y - pos[0].y;
	sort(pos + 1, pos + n, cmp);
	for (int i = 0; i < n; ++i) {
		while (convex.size() > 1 && ccw(convex[convex.size() - 2], convex.back(), pos[i]) <= 0)
			convex.pop_back();
		convex.push_back(pos[i]);
	}
	int ans = 0;
	for (int i = 0; i < convex.size() - 1; ++i) ans += ccw(convex[0], convex[i], convex[i + 1]);
	cout << ans / MOD;
	return 0;
}