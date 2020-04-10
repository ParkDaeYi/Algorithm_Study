#include <iostream>
#include <vector>
#include <queue>
#define MAX_N 501
using namespace std;

class build {
public:
	int idx, time;
	build(int idx = 0, int time = 0) : idx(idx), time(time) {}
};
struct cmp {
	bool operator()(build& b1, build& b2) {
		//return b1.idx == b2.idx ? b1.time > b2.time:b1.idx > b2.idx; 상관없음
		return b1.time == b2.time ? b1.idx > b2.idx:b1.time > b2.time;
	}
};
priority_queue<build, vector<build>, cmp> pq;
int n, bd[MAX_N], indegree[MAX_N];
vector<int> graph[MAX_N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1, v;i < n + 1;++i) {
		cin >> bd[i];
		while (1) {
			cin >> v;
			if (v == -1) break;
			indegree[i]++;
			graph[v].push_back(i);
		}
	}
	for (int i = 1;i < n + 1;++i) {
		if (!indegree[i]) pq.push(build(i, bd[i]));
	}
	while (!pq.empty()) {
		int cur = pq.top().idx;
		pq.pop();
		for (int nxt : graph[cur]) {
			indegree[nxt]--;
			if (!indegree[nxt]) {
				bd[nxt] += bd[cur];
				pq.push(build(nxt, bd[nxt]));
			}
		}
	}
	for (int i = 1;i < n + 1;++i) cout << bd[i] << '\n';
	return 0;
}