#include <iostream>
#include <cmath>
#include <vector>
#define N 100100
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int n, m, p[N];
ll dist[N];
bool visit[N], can[N];
char op;
vector<pll> graph[N], qry;

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return 0;
	// 1 ~ N 번까지 있으므로 p[b] = a 값은 무조건 1 이상임
	return 	p[b] = a;
}

void dfs(int now, ll d) {
	// 재귀를 사용해서 싸이클을 가지는 정점들의 거리를 갱신
	// 처음 시작하는 정점을 기준으로~
	visit[now] = 1;
	dist[now] = d;
	for (pll nxt : graph[now]) {
		if (visit[nxt.first]) continue;
		dfs(nxt.first, d + nxt.second);
	}
}

void solve_1() {

	while (cin >> n >> m) {
		if (!n && !m) break;
		for (int i = 0; i <= n; ++i) p[i] = i, visit[i] = 0, graph[i].clear(), can[i] = 0;
		qry.clear();
		for (int i = 0; i < m; ++i) {
			cin >> op;
			int a, b, c;
			if (op == '!') {
				cin >> a >> b >> c;
				// 문제에서 모든 측정은 정확하고, 일관성을 유지한다고 나와있으므로
				// 유니온 파인드를 통해 확인 해줌
				if (merge(a, b)) {
					graph[a].push_back({ b,c });	// a -> b
					graph[b].push_back({ a,-c });	// b -> a
				}
			}
			else {
				cin >> a >> b;
				// ? 일 경우를 미리 저장 해둠 (바로 처리하지 않음)
				// ==> 그때 그때 길이를 갱신하지 않고 한 번에 하기 위함
				qry.push_back({ a,b });
				if (find(a) != find(b)) can[qry.size() - 1] = 1;
			}
		}
		for (int i = 1; i <= n; ++i) if (!visit[i]) dfs(i, 0);
		for (int i = 0; i < qry.size(); ++i) {
			if (can[i]) cout << "UNKNOWN\n";
			else cout << dist[qry[i].second] - dist[qry[i].first] << '\n';
		}
	}

}

#define N 100001

int n, m, parent[N], weight[N];
char op;

// find 연산 동시에 weight 값을 갱신해줌
// ==>	 초기에 parent 배열에는 자신의 바로 옆 샘플의 정보가 저장되어 있음
//		weight 역시 바로 옆에 있는 샘플과의 무게 차이의 정보만 가지고 있음
//		(weight의 i 값은 샘플 i 와 parent[i] 의 무게 차이를 갖고 있음,
//		ex. i 가 2이고 parent[2] 가 2 이면 weight[2]는 0을 갖게 되고,
//		i 가 1이고 parent[1] 이 2이면 weight[1]는 샘플 1과 2 사이의 무게 차이를 갖고 있음)
// ==>	 find 연산을 통해 parent[x]의 값이 바뀌게 될 경우
//		weight[x]의 값도 그에 맞게 갱신 시켜줘야함
//		만약 parent[1] = 2, parent[2] = 3, parent[3] = 3 일 때  ? 1 3 을 입력 받았다고 해보자
//		3일 경우에는 x == parent[x] 이므로 바로 종료 될 것이다
//		1일 경우에는 재귀로 인해 x가 3이 될 때 종료 된다
//		그 후 x의 값은 2 prev 값은 3이 될 것이다
//		weight[2] 에 weight[3](parent[2]=3) 의 값을 추가하고 종료 한다
//		다시 x가 1이고 prev 는 3이 된다
//		weight[1] 에 weight[2]의 값을 더하면 1 에서 3 까지의 무게 차이를 알 수 있게 된다
//		(x가 2일 때 2에서 3까지의 거리를 구하였으므로 weight[1]에 weight[2]를 더해주면 된다)
//		그리고 parent[1] 을 3으로 갱신하면 된다
int find_2(int x) {
	if (x == parent[x]) return x;
	int prev = find_2(parent[x]);
	weight[x] += weight[parent[x]];
	return parent[x] = prev;
}

void solve_2() {

	while (cin >> n >> m) {
		if (!n && !m) break;
		for (int i = 1; i <= n; ++i) parent[i] = i, weight[i] = 0;
		int a, b, c;
		for (int i = 0; i < m; ++i) {
			cin >> op;
			cin >> a >> b;
			int l = find_2(a);
			int r = find_2(b);
			if (op == '!') {
				cin >> c;
				if (l != r) {
					// a 에서 b 까지의 무게 차이를 저장
					// parent를 통해 현재 l이 r까지의 값을 갖고 있다는 것을 알 수 있음
					// weight[b] - weight[a]를 해주는 이유는
					// 별개로 있던 그래프가 합쳐질 수도 있기 때문임
					parent[l] = r;
					weight[l] = weight[b] - weight[a] + c;
				}
			}
			else {
				if (l != r) cout << "UNKNOWN\n";
				else cout << weight[a] - weight[b] << '\n';
			}
		}
	}

}