#include <iostream>
using namespace std;

int n, m, arr[9];
bool visited[9];

void backt(int,int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	backt(0, 0);
	return 0;
}

void backt(int depth, int idx) {
	if (depth == m) {
		for (int i = 0; i < m; ++i) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = idx; i < n; ++i) {
		if (visited[i]) continue;
		visited[i] = 1;
		arr[depth] = i + 1;
		backt(depth + 1, i + 1);
		visited[i] = 0;
	}
	return;
}