#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 100000
using namespace std;
typedef long long int llt;

class info {
public:
	int x, y, p, q;
	info(int x = 0, int y = 0) :x(x), y(y), p(0), q(0) {}
	info operator-(info& a) {
		return info(x - a.x, y - a.y);
	}
}pos[MAX];
int n;
vector<info> convex;

bool cmp(const info& a, const info& b) {
	if (1LL * a.q * b.p != 1LL * a.p * b.q) return 1LL * a.q * b.p < 1LL * a.p * b.q;
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

llt ccw(info a, info b, info c) {
	return 1LL * (a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x);
}

llt dist(info a, info b) {
	llt dx = b.x - a.x, dy = b.y - a.y;
	return dx * dx + dy * dy;
}

double rotatingCalipers() {
	llt ret = -1;
	int m = convex.size();
	for (int i = 0, j = 0; i < m; ++i) {
		//구간의 양 끝이 [A,B]라고 가정한다면
		//A번째 점과 A+1번째 점을 잇는 선분과 B번째 점과 B+1번째 점을 잇는 선분의
		//외적을 계산, https://degurii.tistory.com/47
		while (j + 1 < m && ccw(info(0,0), convex[i + 1] - convex[i], convex[j + 1] - convex[j]) >= 0)
			ret = max(ret, dist(convex[i], convex[j++]));
		ret = max(ret, dist(convex[i], convex[j]));
	}
	return sqrt(ret);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> pos[i].x >> pos[i].y;
	sort(pos, pos + n, cmp);
	for (int i = 1; i < n; ++i) pos[i].p = pos[i].x - pos[0].x, pos[i].q = pos[i].y - pos[0].y;
	sort(pos + 1, pos + n, cmp);
	for (int i = 0; i < n; ++i) {
		//convex.size()-2 : first, convex.back() : second, pos[i] : next
		//ccw가 시계 방향이거나 일직선이면 pop 시킴
		while (convex.size() > 1 && ccw(convex[convex.size() - 2], convex.back(), pos[i]) <= 0)
			convex.pop_back();
		convex.push_back(pos[i]);
	}
	cout << fixed;
	cout.precision(8);
	cout << rotatingCalipers();
	return 0;
}