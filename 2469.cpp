#include <iostream>
using namespace std;

int n, k, q;
char line[1001][27];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> k >> n;
	char start[27], end[27], ans[27];
	for (int i = 0; i < k; ++i) start[i] = 'A' + i;
	for (int i = 0; i < k; ++i) cin >> end[i];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k - 1; ++j) {
			cin >> line[i][j];
			if (line[i][j] == '?') q = i;
		}
	}
	for (int i = 0; i < q; ++i) {
		for (int j = 0; j < k - 1; ++j) {
			if (line[i][j] == '*') continue;
			swap(start[j], start[j + 1]);
		}
	}
	for (int i = n - 1; i > q; --i) {
		for (int j = 0; j < k - 1; ++j) {
			if (line[i][j] == '*') continue;
			swap(end[j], end[j + 1]);
		}
	}
	for (int i = 0; i < k - 1; ++i) {
		if (start[i] != end[i]) ans[i] = '-';
		else ans[i] = '*';
	}
	for (int i = 0; i < k - 1; ++i) {
		if (ans[i] == '*') continue;
		swap(start[i], start[i + 1]);
		ans[i++ + 1] = '*';
	}
	bool flag = 0;
	for (int i = 0; i < k - 1; ++i) {
		if (start[i] == end[i]) continue;
		flag = 1;
		break;
	}
	if (flag) for (int i = 0; i < k - 1; ++i) cout << 'x';
	else for (int i = 0; i < k - 1; ++i) cout << ans[i];
	return 0;
}