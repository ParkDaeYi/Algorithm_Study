#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[8], ans[8];

void backt(int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	backt(0);
	return 0;
}

void backt(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; ++i) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	bool visited[10001] = { 0, };
	for (int i = 0; i < n; ++i) {
		if (visited[arr[i]]) continue;
		visited[arr[i]] = 1;
		ans[depth] = arr[i];
		backt(depth + 1);

	}
	return;
}