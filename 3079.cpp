#include <iostream>
using namespace std;
typedef long long int llt;

int n, m, k[100001];
llt _max;

bool chk(llt);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; 
	for (int i = 0; i < n; ++i) {
		cin >> k[i];
		_max = _max > k[i] ? _max : k[i];
	}
	llt left = 1, right = _max * m, mid, ans = _max * m;
	while (left <= right) {
		mid = (left + right) / 2;
		if (chk(mid)) {
			ans = ans > mid ? mid : ans;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	cout << ans;
	return 0;
}

bool chk(llt time) {
	llt ret = 0;
	for (int i = 0; i < n; ++i) ret += time / k[i];
	return ret >= m;
}