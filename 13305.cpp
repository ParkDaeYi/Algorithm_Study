#include <iostream>
using namespace std;
typedef long long int llt;

int cost, dist[100000], n, pv = 1e9 + 1;
llt ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; ++i) cin >> dist[i];
	for (int i = 0; i < n - 1; ++i) {
		cin >> cost;
		pv = pv > cost ? cost : pv;
		ans += (llt)pv * dist[i];
	}
	cout << ans;
	return 0;
}