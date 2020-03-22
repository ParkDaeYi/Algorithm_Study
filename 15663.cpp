#include <iostream>
#include <algorithm>
using namespace std;

int arr[8],op[8], N, M;
bool visited[8];

void dfs(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) cin >> arr[i];
	sort(arr, arr + N);
	dfs(0);
    return 0;
}

void dfs(int depth) {

	if (depth == M) {
		for (int i = 0; i < M; ++i) cout << op[i] << ' ';
		cout << '\n';
		return;
	}
	int tmp = 0;
	for (int i = 0; i < N; ++i) {
		if (!visited[i] && tmp != arr[i]) {
			visited[i] = true;
			op[depth] = arr[i];
			tmp = arr[i];
			dfs(depth + 1);
			visited[i] = false;
		}
	}
    return;
}