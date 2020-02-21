#include <iostream>
using namespace std;
typedef long long int llt;

llt n, k, lan[10000], _max, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> lan[i];
		_max = _max > lan[i] ? _max : lan[i];
	}
	llt left = 1, right = _max, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		llt sum = 0;
		for (int i = 0; i < n; ++i) sum += lan[i] / mid;
		if (sum >= k) {
			ans = ans > mid ? ans : mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout << ans;
	return 0;
}