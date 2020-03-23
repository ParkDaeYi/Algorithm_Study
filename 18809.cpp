#include <iostream>
#include <queue>
#include <vector>
#pragma warning (disable:4996)
using namespace std;
typedef pair<int, int> pii;

int n, m, r, g, mp[51][51], dy[4] = { 1,-1,0,0 }, dx[4] = { 0,0,1,-1 };
int garden[51][51], ans, grn[5], red[5], sz;
bool used[11];
vector<pii> info;

int max_int(int a, int b) {
	return a > b ? a : b;
}

int solve() {
	pii state[51][51];
	queue<pii> q;
	for (int i = 0;i < g;++i) {
		state[info[grn[i]].first][info[grn[i]].second] = pii(0, 1);
		q.push(info[grn[i]]);
	}
	for (int i = 0;i < r;++i) {
		state[info[red[i]].first][info[red[i]].second] = pii(0, 2);
		q.push(info[red[i]]);
	}
	int cnt = 0;
	while (!q.empty()) {
		int y = q.front().first, x = q.front().second;
		q.pop();
		int curtime = state[y][x].first;
		int curcolor = state[y][x].second;
		if (state[y][x].second == 3) continue;
		for (int i = 0;i < 4;++i) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (!mp[ny][nx]) continue;
			if (!state[ny][nx].second) {
				state[ny][nx] = pii(curtime + 1, curcolor);
				q.push(pii(ny, nx));
			}
			else if (state[ny][nx].second == 1) {
				if (curcolor == 2 && state[ny][nx].first == curtime + 1) {
					cnt++;
					state[ny][nx].second = 3;
				}
			}
			else if (state[ny][nx].second == 2) {
				if (curcolor == 1 && state[ny][nx].first == curtime + 1) {
					cnt++;
					state[ny][nx].second = 3;
				}
			}
		}
	}
	return cnt;
}

void backtrack_g(int depth,int idx) {
	if (depth == g) {
		ans = max_int(ans, solve());
		return;
	}
	for (int i = idx;i < sz;++i) {
		if (used[i]) continue;
		used[i] = 1;
		grn[depth] = i;
		backtrack_g(depth + 1, i + 1);
		used[i] = 0;
	}
	return;
}

void backtrack_r(int depth,int idx) {
	if (depth == r) {
		backtrack_g(0, 0);
		return;
	}
	for (int i = idx;i < sz;++i) {
		if (used[i]) continue;
		used[i] = 1;
		red[depth] = i;
		backtrack_r(depth + 1, i + 1);
		used[i] = 0;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> r >> g;
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m;++j) {
			cin >> mp[i][j];
			if (mp[i][j] == 2) info.push_back(pii(i, j));
		}
	}
	sz = info.size();
	backtrack_r(0, 0);
	cout << ans;
	return 0;
}