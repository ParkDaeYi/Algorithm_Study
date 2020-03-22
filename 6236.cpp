#include <iostream>
using namespace std;

int n, m, sum, arr[100000], ans;

bool chk(int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	int left = 1, right = sum, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (chk(mid)) {
			ans = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	cout << ans;
	return 0;
}

bool chk(int mid) {
	int cnt = 1, sum = mid;
	for (int i = 0; i < n; ++i) {
		if (mid < arr[i]) return 0;
		if (sum - arr[i] < 0) {
			sum = mid;
			cnt++;
		}
		sum -= arr[i];
	}
	return m >= cnt;
}
