#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t, n, arr[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0, a, b;i < n;++i) {
			cin >> a >> b;
			arr[a - 1] = b - 1;
		}
		int ans = 1, cmp = arr[0];
		for (int i = 1;i < n;++i) if (cmp > arr[i]) {
			ans++;
			cmp = arr[i];
		}
		cout << ans << '\n';
	}
	return 0;
}