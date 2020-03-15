#include <iostream>
#include <algorithm>
using namespace std;

int n, m, six_min = 1001, one_min = 1001;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0, s, o; i < m; ++i) {
		cin >> s >> o;
		six_min = min(six_min, s);
		one_min = min(one_min, o);
	}
	int d = n / 6, ss, oo, so;
	bool flag = 0;
	if (n % 6 == 0) flag = 1;
	flag ? ss = six_min * d : ss = six_min * (d + 1);
	oo = one_min * n;
	so = d * six_min + (n % 6) * one_min;
	int ans = min(so, min(ss, oo));
	cout << ans;
	return 0;
}