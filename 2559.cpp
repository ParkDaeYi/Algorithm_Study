#include <iostream>
using namespace std;

int n, k, arr[100001], ans = -1e9;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 1;i <= n;++i) cin >> arr[i], arr[i] += arr[i - 1];
	for (int i = k;i <= n;++i) {
		int v = arr[i] - arr[i - k];
		ans = ans < v ? v : ans;
	}
	cout << ans;
	return 0;
}