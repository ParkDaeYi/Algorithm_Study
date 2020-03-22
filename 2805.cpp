#include <iostream>
using namespace std;
typedef long long int llt;

int n, m, tr[1000000], _max;
llt ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> tr[i];
		_max = _max > tr[i] ? _max : tr[i];
	}
	int left = 1, right = _max, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		llt sum = 0;
		for (int i = 0; i < n; ++i) sum += (tr[i] - mid) > 0 ? (tr[i] - mid) : 0;	
		if (m <= sum) {
			ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout << ans;
	return 0;
}