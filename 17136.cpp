#include <iostream>
#define N 10
#define INF 2e9
using namespace std;

int mp[N][N], used[5] = { 5,5,5,5,5 }, ans = INF;

int min_int(int a, int b) {
	return a > b ? b : a;
}

bool chk(int y, int x, int num) {
	if (y + num > N || x + num > N) return 0;
	for (int i = y;i < y + num;++i) {
		for (int j = x;j < x + num;++j) {
			if (!mp[i][j]) return 0;
		}
	}
	return 1;
}

void change_arr(int y, int x, int num,int val) {  for (int i = y;i < y + num;++i) for (int j = x;j < x + num;++j) mp[i][j] = val; }

void backtrack(int y, int x, int cnt) {
	if (x == N) {
		backtrack(y + 1, 0, cnt); return;
	}
	if (y == N) {
		ans = min_int(ans, cnt); return;
	}
	if (!mp[y][x]) {
		backtrack(y, x + 1, cnt); return;
	}
	for (int i = 4;i >= 0;--i) {
		if (!used[i] || !chk(y, x, i + 1)) continue;
		used[i]--;
		change_arr(y, x, i + 1, 0);
		backtrack(y, x + i + 1, cnt + 1);
		change_arr(y, x, i + 1, 1);
		used[i]++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0;i < N;++i) for (int j = 0;j < N;++j) cin >> mp[i][j];
	backtrack(0, 0, 0);
	ans == INF ? cout << -1 : cout << ans;
	return 0;
}