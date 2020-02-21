#include <iostream>
#include <algorithm>
using namespace std;

int n, c, arr[200000], ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	int left = 1, right = arr[n - 1] - arr[0], mid;
	while (left <= right) {
		mid = (left + right) / 2;
		int cnt = 1, prev = arr[0];
		for (int i = 1; i < n; ++i) {
			if (arr[i] - prev < mid) continue;
			cnt++;
			prev = arr[i];
		}
		if (cnt < c) right = mid - 1;
		else {
			ans = ans > mid ? ans : mid;
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}