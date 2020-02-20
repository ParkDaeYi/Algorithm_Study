#include <iostream>
using namespace std;

int n, arr[10000], m, _max, ans;

bool chk(int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		_max = _max > arr[i] ? _max : arr[i];
	}
	cin >> m;
	int left = 1, right = _max, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (chk(mid)) {
			ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout << ans;
	return 0;
}

bool chk(int mid) {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (mid < arr[i]) sum += mid;
		else sum += arr[i];
	}
	return sum <= m;
}