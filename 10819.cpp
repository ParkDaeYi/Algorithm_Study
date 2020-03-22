#include <iostream>
using namespace std;

int n, ans, arr[8], res[8];
bool used[8];

int _abs(int x) {
	return x < 0 ? -x : x;
}
void dfs(int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	dfs(0);
	cout << ans;
	return 0;
}

void dfs(int idx) {
	if (idx == n) {
		int sum = 0;
		for (int i = 0; i < n - 1; ++i) sum += _abs(res[i] - res[i + 1]);
		ans = ans > sum ? ans : sum;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (used[i]) continue;
		used[i] = 1;
		res[idx] = arr[i];
		dfs(idx + 1);
		used[i] = 0;
	}
	return;
}