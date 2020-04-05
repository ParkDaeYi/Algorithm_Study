#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int llt;

class point {
public:
	llt x, y, nx, ny;
	point(llt x = 0, llt y = 0) :x(x), y(y), nx(0), ny(0) {}
	bool operator<(const point& p) const {
		if (ny * p.nx != nx * p.ny) return ny * p.nx < nx* p.ny;
		return x == p.x ? y < p.y : x < p.x;
	}
}pos[100001];
int n;
char op;

llt ccw(point a, point b, point c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

bool cmp(const point& p1, const point& p2) {
	llt chk = ccw(pos[0], p1, p2);
	if (chk) return chk > 0;
	if (!chk) return p1.y > p2.y;
	return p1 < p2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0;i < n;++i) {
		cin >> pos[i].x >> pos[i].y >> op;
		if (op == 'N') i--, n--;
	}
	sort(pos, pos + n);
	for (int i = 1;i < n;++i) pos[i].nx = pos[i].x - pos[0].x, pos[i].ny = pos[i].y - pos[0].y;
	sort(pos + 1, pos + n, cmp);
	cout << n << '\n';
	for (int i = 0;i < n;++i) cout << pos[i].x << ' ' << pos[i].y << '\n';
	return 0;
}