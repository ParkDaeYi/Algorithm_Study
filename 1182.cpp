#include <iostream>
using namespace std;

int n, s, arr[20], cnt;

void dfs(int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	dfs(0, 0);
	cout << cnt;
	return 0;
}

void dfs(int idx, int sum) {
	if (idx == n) return;
	sum += arr[idx];
	if (sum == s) ++cnt;
	dfs(idx + 1, sum);
	dfs(idx + 1, sum - arr[idx]);
}