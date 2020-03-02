#include <iostream>
#include <vector>
using namespace std;

int n, m, ans, arr[100], used[100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) cin >> arr[i];
	for (int i = 0; i < m; ++i) {
		bool flag = 0;
		for (int j = 0; j < n; ++j) if (used[j] == arr[i]) { flag = 1; break; }
		if (flag) continue;
		for (int j = 0; j < n; ++j) {
			if (!used[j]) {
				used[j] = arr[i];
				flag = 1;
				break;
			}
		}
		if (flag) continue;
		ans++;
		int idx, prev = -1;
		for (int j = 0; j < n; ++j) {
			int cnt = 0;
			for (int k = i; k < m; ++k) {
				if (used[j] == arr[k]) break;
				cnt++;
			}
			if (cnt > prev) {
				idx = j;
				prev = cnt;
			}
		}
		used[idx] = arr[i];
	}
	cout << ans;
	return 0;
}