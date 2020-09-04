#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, m, t, d, h[25][25];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
char map[25][25];
vector<pii> x[625], z[625];

inline int _pow(int a) { return a * a; }
inline int _abs(int a) { return a < 0 ? -a : a; }

vector<int> dij(vector<pii> g[]) {
	vector<int> dist(n * m, 1e9);
	priority_queue<pii, vector<pii>, less<pii>> pq;
	pq.push({ 0,0 });
	dist[0] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second, cost = -pq.top().first;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (pii& i : g[cur]) {
			int nxt = i.second, ncost = i.first;
			if (dist[nxt] > dist[cur] + ncost) {
				dist[nxt] = dist[cur] + ncost;
				pq.push({ -dist[nxt],nxt });
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> t >> d;
	char c;
	for (int i = 0;i < n;++i) for (int j = 0;j < m;++j) {
		cin >> c;
		if ('A' <= c && c <= 'Z') h[i][j] = c - 'A';
		else h[i][j] = c - 'a' + 26;
	}
	// 당연히 [0,0] 에서 가는 경로를 연결해준다.
	// 그리고 벡터를 하나 추가하여 똑같이 연결은 하지만
	// 코스트를 반대로해서 연결한다
	// 즉 이 벡터는 돌아오는 비용(시간)을 의미한다
	for (int i = 0;i < n;++i) for (int j = 0;j < m;++j) for (int k = 0;k < 4;++k) {
		int ny = i + dy[k], nx = j + dx[k];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		int s = h[i][j], e = h[ny][nx], cur = i * m + j, nxt = ny * m + nx;
		if (_abs(s - e) > t) continue;
		if (s >= e) x[cur].emplace_back(pii(1, nxt));
		else x[cur].emplace_back(pii(_pow(s - e), nxt));
		if (s <= e) z[cur].emplace_back(pii(1, nxt));
		else z[cur].emplace_back(pii(_pow(s - e), nxt));
	}
	vector<int> dx = dij(x);
	vector<int> dz = dij(z);
	int ans = h[0][0];
	for (int i = 0;i < n;++i) for (int j = 0;j < m;++j) {
		// [0, 0]에서 가는 값과 [0, 0]으로 오는 값을 통해 정답을 구한다 
		if (dx[i * m + j] + dz[i * m + j] <= d) {
			ans = max(ans, h[i][j]);
		}
	}
	cout << ans;
	return 0;
}