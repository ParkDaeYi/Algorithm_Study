#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#define N 105
#define D 5.0
#define x first
#define y second
using namespace std;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;

int n;
pdd arr[N], s, e;
vector<pdi> g[N];
double dist[N];

inline double d(int a, int b) {
	double xx = arr[a].x - arr[b].x, yy = arr[a].y - arr[b].y;
	return sqrt(xx * xx + yy * yy);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s.x >> s.y >> e.x >> e.y;
	cin >> n;
	arr[0] = s, arr[n + 1] = e;
	for (int i = 1;i <= n;++i) cin >> arr[i].x >> arr[i].y;
	for (int i = 0;i <= n;++i) for (int j = i + 1;j <= n + 1;++j) {
		double a = d(i, j) / D;
		double b = 2.0 + fabs(d(i, j) - 50.0) / D;
		double c = !i ? a : min(a, b);	// 시작점에서는 대포까지 걸어가야함
		g[i].emplace_back(pdi(c, j));
		g[j].emplace_back(pdi(c, i));
	}
	// 기존 다익스트라와 동일
	priority_queue<pdi, vector<pdi>, less<pdi>> pq;
	pq.push({ 0,0 });
	fill(dist, dist + n + 2, 1e9);
	dist[0] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second, cost = -pq.top().first;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (pdi& i : g[cur]) {
			int nxt = i.second; double ncost = i.first;
			if (dist[nxt] > dist[cur] + ncost) {
				dist[nxt] = dist[cur] + ncost;
				pq.push({ -dist[nxt],nxt });
			}
		}
	}
	cout.precision(6);
	cout << fixed << dist[n + 1];
	return 0;
}

// 그래프를 따로 설정하지 않고 푼 풀이
bool visit[N];

int solve_2() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s.x >> s.y >> e.x >> e.y;
	cin >> n;
	arr[0] = s, arr[n + 1] = e;
	for (int i = 1;i <= n;++i) cin >> arr[i].x >> arr[i].y;
	priority_queue<pdi, vector<pdi>, less<pdi>> pq;
	pq.push({ 0,0 });
	fill(dist, dist + n + 2, 1e9);
	dist[0] = 0;
	bool f = 1;
	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visit[cur]);	// 블로그에서 이렇게 하길래 따라해봄
		visit[cur] = 1;
		// 그래프로 연결하건 안하건
		// 어짜피 전부 다 비교해야함
		for (int i = 1;i <= n + 1;++i) {
			double a = d(cur, i) / D;
			double b = 2.0 + fabs(d(cur, i) - 50.0) / D;
			double c = f ? a : min(a, b);
			if (dist[i] > dist[cur] + c) {
				dist[i] = dist[cur] + c;
				pq.push({ -dist[i],i });
			}
		}
		f = 0;	// 위 풀이와 같이 시작점만 따로 처리
	}
	cout.precision(6);
	cout << fixed << dist[n + 1];
	return 0;
}