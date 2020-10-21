#include <iostream>
#include <vector>
using namespace std;

int n, sz = 2, arr[1 << 10];
vector<int> t[10];

// 입력으로 중위 순회가 주어짐
// s 와 e 의 가운데 값은 해당 높이의 노드에 속함
void dfs(int s, int e, int h) {
	if (s == e) return;
	int m = s + e >> 1;
	t[h].emplace_back(arr[m]);
	dfs(s, m, h + 1);
	dfs(m + 1, e, h + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int tmp = n;
	while (--tmp) sz *= 2;
	sz -= 1;
	for (int i = 0;i < sz;++i) cin >> arr[i];
	dfs(0, sz, 0);
	for (int i = 0;i < n;++i) {
		for (int v : t[i]) cout << v << ' ';
		cout << '\n';
	}
	return 0;
}