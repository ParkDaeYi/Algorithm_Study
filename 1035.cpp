#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;

char map[5][5];
bool used[5][5], visit[5][5];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 }, ans = 1e2;
vector<pii> star;

int cnt(pii p) {
	// 인접한 '*'의 개수를 반환
	int y = p.first, x = p.second;
	visit[y][x] = 1;
	int ret = 1;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
		if (!used[ny][nx] || visit[ny][nx]) continue;
		ret += cnt({ ny, nx });
	}
	return ret;
}

pii findPos() {
	// 아무거나 하나 찾으면 됨
	// dfs 함수를 통해 인접한 '*' 의 개수를 체크하고
	// 어짜피 인접해 있지 않으면 현재 '*' 의 개수와 같은 값이 나오지 않으므로
	// 아무거나 '*' 이 있는 곳을 반환
	for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) if (used[i][j]) return { i,j };
}

bool can() {
	memset(visit, 0, sizeof(visit));
	return cnt(findPos()) == star.size();
}

void solve(int n, int dist) {
	if (dist >= ans) return;
	if (n == star.size()) {
		if (can()) if (ans > dist) ans = dist;
		return;
	}

	for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) {
		// ****.		***.*		***..
		// .....		.....		*....
		// .....	=>	.....	=>	.....
		// .....		.....		.....
		// .....		.....		.....	순서로 진행
		// '*' 들의 가능한 모든 위치를 검사
		if (used[i][j]) continue;
		used[i][j] = 1;
		solve(n + 1, dist + abs(i - star[n].first) + abs(j - star[n].second));
		used[i][j] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) {
		cin >> map[i][j];
		if (map[i][j] == '*') star.push_back({ i,j });
	}
	solve(0, 0);
	cout << ans;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;

pii star[5], dest[5];
char map[5][5];
int cnt, idx[5] = { 0,1,2,3,4 }, ans = 1e2;
bool used[5][5], visit[5][5];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,-1,0,1 };

inline int getDist(pii &p1, pii &p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int dfs(pii p) {
	int y = p.first, x = p.second;
	visit[y][x] = 1;
	int ret = 1;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
		if (!used[ny][nx] || visit[ny][nx]) continue;
		ret += dfs({ ny, nx });
 	}
	return ret;
}

pii findPos() {
	for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) if (used[i][j]) return { i,j };
}

void solve(int depth, int n) {
	if (depth == cnt) {
		int len = dfs(findPos());
		if (len == cnt) {
			do {
				int cost = 0;
				for (int i = 0; i < cnt; ++i) cost += getDist(star[idx[i]], dest[i]);
				ans = min(ans, cost);
			} while (next_permutation(idx, idx + cnt));
			// next_permutation
			// -> 현재 나와 있는 수열에서 인자로 넘어간 범위에 해당하는 다음 순열을 구하고 true를 반환
			// 다음 순열이 없다면(다음에 나온 순열이 순서상 이전 순열보다 작다면) false를 반환
			// ex. 1 1 0
			//	0 1 1
			//	1 0 1
			//	1 1 0
			// 중복이 있는 원소의 경우 중복인 경우를 제외하고 순열을 만들어줌.
		}
		memset(visit, 0, sizeof(visit));
		return;
	}
	for (int i = n; i < 25; ++i) {
		// ****.		***.*		***..
		// .....		.....		*....
		// .....	=>	.....	=>	.....
		// .....		.....		.....
		// .....		.....		.....	순서로 진행
		// '*' 들의 가능한 모든 위치를 검사
		used[i / 5][i % 5] = 1;
		dest[depth] = { i / 5,i % 5 };
		solve(depth + 1, i + 1);
		used[i / 5][i % 5] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) {
		cin >> map[i][j];
		if (map[i][j] == '*') star[cnt++] = { i,j };
	}
	solve(0, 0);
	cout << ans;
	return 0;
}