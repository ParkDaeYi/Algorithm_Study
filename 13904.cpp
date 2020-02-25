#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> pii;

int n, d[1001], ans;
pii dw[1000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> dw[i].second >> dw[i].first;
	sort(dw, dw + n, greater<pii>());
	for (int i = 0; i < n; ++i) {
		int idx = dw[i].second;
		if (!d[idx]) d[idx] = dw[i].first;
		else {
			while (d[--idx]);
			if (idx) d[idx] = dw[i].first;
		}
	}
	for (int i = 1; i <= 1000; ++i) ans += d[i];
	cout << ans;
	return 0;
}