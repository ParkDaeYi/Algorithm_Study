#include <iostream>
using namespace std;

int n, arr[5], ma, res, ans;

void solve(int idx, int cnt, int sum) {
	if (cnt == 3) {
		int s = sum % 10;
		ma = ma < s ? s : ma;
		return;
	}
	if (idx == 5) return;
	solve(idx + 1, cnt + 1, sum + arr[idx]);
	solve(idx + 1, cnt, sum);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < 5;++j) cin >> arr[j];
		ma = 0;
		solve(0, 0, 0);
		if (res <= ma) {
			res = ma;
			ans = i + 1;
		}
	}
	cout << ans;
	return 0;
}