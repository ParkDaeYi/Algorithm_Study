#include <iostream>
#include <algorithm>
using namespace std;

int ss[10000], dist[9999], n, k, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> ss[i];
	sort(ss, ss + n);
	for (int i = 0; i < n - 1; ++i) dist[i] = ss[i + 1] - ss[i];
	sort(dist, dist + n - 1);
	for (int i = 0; i < n - k; ++i) ans += dist[i];
	cout << ans;
	return 0;
}