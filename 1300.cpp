#include <iostream>
#include <algorithm>
using namespace std;

int n, k, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	int left = 1, right = k, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 1; i <= n; ++i) cnt += min(mid / i, n);
		if (cnt < k) left = mid + 1;
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
