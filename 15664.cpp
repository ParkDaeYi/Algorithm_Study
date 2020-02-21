#include <iostream>
#include <algorithm>
using namespace std;

int N, M, arr[8], op[8];
bool visited[8];

void dfs(int, int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) cin >> arr[i];
	sort(arr, arr + N);
	dfs(0, 0, -1);
	return 0;
}

void dfs(int depth,int idx,int before) {
	if (depth == M) {
		for (int i = 0; i < M; ++i) cout << op[i] << ' ';
		cout << '\n';
		return;
	}
	int tmp = 0;
	for (int i = idx; i < N; ++i) {
		if (!visited[i] && tmp != arr[i] && before <= arr[i]) {
			visited[i] = 1;
			op[depth] = arr[i];
			tmp = arr[i];
			dfs(depth + 1, idx + 1, arr[i]);
			visited[i] = 0;
		}
	}
    return;
}