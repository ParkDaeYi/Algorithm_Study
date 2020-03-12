#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define PI 3.1415926535 //이문제 PI 많이 적으니까 맞음;;
#define MAX 1001
using namespace std;
typedef long long int llt;
typedef pair<llt, llt> pll;

class point {
public:
	llt x, y, dx, dy;
	point(llt x = 0, llt y = 0) :x(x), y(y), dx(0), dy(0) {}
	bool operator <(const point& p) const {
		if (dy * p.dx != dx * p.dy) return dy * p.dx < dx * p.dy;
		return y == p.y ? x < p.x : y < p.y;
	}
}pos[MAX];
int n, l;

int ccw(point a, point b, point c) {
	llt tmp = a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
	return tmp == 0 ? 0 : tmp > 0 ? 1 : -1;
}

double dist(point a, point b) {
	llt dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

llt invec(pll p1, pll p2) {
	//벡터 내적
	//v1.x * v2.x + v1.y * v2.y
	return p1.first * p2.first + p1.second * p2.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> l;
	for (int i = 0; i < n; ++i) cin >> pos[i].x >> pos[i].y;
	for (int i = 0; i < n; ++i) {
		if (pos[i] < pos[0]) swap(pos[i], pos[0]);
	}
	for (int i = 1; i < n; ++i) pos[i].dx = pos[i].x - pos[0].x, pos[i].dy = pos[i].y - pos[0].y;
	sort(pos + 1, pos + n);
	vector<point> convex;
	for (int i = 0; i < n; ++i) {
		while (convex.size() > 1 && ccw(convex[convex.size() - 2], convex.back(), pos[i]) <= 0)
			convex.pop_back();
		convex.push_back(pos[i]);
	}
	double ans = 0;
	n = convex.size();
	for (int i = 0; i < n; ++i) {
		point prev = convex[(i + n - 1) % n], cur = convex[i], next = convex[(i + 1) % n];
		double vec1 = dist(cur, next);
		ans += vec1;
		double vec2 = dist(prev, cur);
		/*
		벡터구하기
		=> 종점 - 시점, prev와 next가 종점, cur이 시점
		*/
		/*
		사이각(회전각)은 내적을 이용해서 구함
		사이각(theta) = arccos * 내적/(v1 크기 * v2 크기)
		arccos == cos^-1
		*/
		llt inner = invec(pll(prev.x - cur.x, prev.y - cur.y), pll(next.x - cur.x, next.y - cur.y));
		double theta = acos((double)inner / vec1 / vec2);
		theta = PI - theta;
		/*
		theta가 아닌 PI - theta 크기를 바로 알고 싶으면
		(v1 * -1 , v2)내적 / (v1 크기 * v2 크기)
		로 하면 됨
		*/
		ans += l * theta;
	}
	cout << fixed;
	cout.precision(0);
	cout << ans;
	return 0;
}