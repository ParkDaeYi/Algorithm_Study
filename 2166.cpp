#include <iostream>
#include <utility>
#include <cmath>
using namespace std;
typedef long double ld;
typedef pair<ld, ld> pll;

int n;
pll pos[10000];
ld ans;

ld ccw(pll, pll, pll);
ld ccw(pll, pll);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> pos[i].first >> pos[i].second;
	for (int i = 0; i < n - 1; ++i) ans += ccw(pos[0], pos[i], pos[i + 1]);
	cout << fixed;
	cout.precision(1);
	cout << abs(ans / 2);
	return 0;
}

ld ccw(pll p1, pll p2, pll p3) {
	return ccw(pll(p2.first - p1.first, p2.second - p1.second), pll(p3.first - p1.first, p3.second - p1.second));
}

ld ccw(pll p1, pll p2) {
	return p1.first * p2.second - p1.second * p2.first;
}