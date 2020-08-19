#include <iostream>
#define N 11
#define INF 0x7fffffff
using namespace std;

int n, arr[N + 1], op[4], ma = -INF, mi = INF;

int menu(int num, int a, int b) {
	int ret = 0;
	switch (num) {
	case 0: ret = a + b; break;
	case 1: ret = a - b; break;
	case 2: ret = a * b; break;
	case 3: ret = a / b; break;
	}
	return ret;
}

void dfs(int res, int depth) {
	if (depth == n) {
		if (ma < res) ma = res;
		if (mi > res) mi = res;
		return;
	}
	for (int i = 0;i < 4;++i) {
		if (!op[i]) continue;
		op[i]--;
		dfs(menu(i, res, arr[depth]), depth + 1);
		op[i]++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0;i < n;++i) cin >> arr[i];
	for (int i = 0;i < 4;++i) cin >> op[i];
	dfs(arr[0], 1);
	cout << ma << '\n' << mi;
	return 0;
}