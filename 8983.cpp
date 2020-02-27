#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int m, n, l, posX[100000], ans;
pii ani[100000];

inline int cal(int x, int a, int b) {
	return abs(x - a) + b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> n >> l;
	for (int i = 0; i < m; ++i) cin >> posX[i];
	for (int i = 0; i < n; ++i) cin >> ani[i].first >> ani[i].second;
	sort(posX, posX + m);
	sort(ani, ani + n);
	for (int i = 0, xidx = 0; i < n; ++i) {
		while (xidx != m - 1 && posX[xidx + 1] < ani[i].first) xidx++;	
		if (cal(posX[xidx], ani[i].first, ani[i].second) <= l) {
			ans++;
			continue;
		}
		if (xidx != m - 1) {
			if (cal(posX[xidx + 1], ani[i].first, ani[i].second) <= l) {
				ans++;
				continue;
			}
		}
	}
	cout << ans;
	return 0;
}