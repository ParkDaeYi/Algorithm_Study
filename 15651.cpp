#include <iostream>
using namespace std;

int n, m, arr[8];

void backt(int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	backt(0);
	return 0;
}

void backt(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; ++i) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; ++i) {
		arr[depth] = i + 1;
		backt(depth + 1);
	}
	return;
}