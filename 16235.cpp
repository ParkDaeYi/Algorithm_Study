#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int n, m, year, A[11][11], AC[11][11];
int dy[8] = { 1,-1,0,0,1,1,-1,-1 };
int dx[8] = { 0,0,1,-1,1,-1,1,-1 };
vector<pii> tree[11][11];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> year;
	for (int i = 0;i < n;++i) for (int j = 0;j < n;++j) cin >> AC[i][j], A[i][j] = 5;
	for (int i = 0, x, y, v;i < m;++i) {
		cin >> x >> y >> v;
		tree[x - 1][y - 1].push_back(pii(v, 1));
	}
	while (year--) {
		for (int i = 0;i < n;++i) {
			for (int j = 0;j < n;++j) {
				int dead = 0;
				for (int k = tree[i][j].size() - 1;k >= 0;--k) {
					int age = tree[i][j][k].first;
					int cnt = tree[i][j][k].second;
					int sum = age * cnt;
					if (A[i][j] >= sum) {
						A[i][j] -= sum;
						tree[i][j][k].first++;
					}
					else {
						int alive_cnt = A[i][j] / age;
						int dead_cnt = cnt - alive_cnt;
						dead += dead_cnt * (age / 2);
						if (!alive_cnt) tree[i][j].erase(tree[i][j].begin() + k);
						else {
							A[i][j] -= alive_cnt * age;
							tree[i][j][k].second = alive_cnt;
							tree[i][j][k].first++;
						}						
					}
				}
				A[i][j] += dead + AC[i][j];
			}
		}

		for (int i = 0;i < n;++i) {
			for (int j = 0;j < n;++j) {
				for (pii v : tree[i][j]) {
					if (v.first % 5 == 0) {
						int cnt = v.second;
						for (int k = 0;k < 8;++k) {
							int ny = i + dy[k], nx = j + dx[k];
							if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
							if (tree[ny][nx].size() == 0 || tree[ny][nx].back().first != 1)
								tree[ny][nx].push_back(pii(1, cnt));
							else
								tree[ny][nx].back().second += cnt;
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			for (pii v : tree[i][j]) ans += v.second;
		}
	}
	cout << ans;
	return 0;
}