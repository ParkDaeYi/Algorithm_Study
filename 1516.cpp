#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct build {
	int idx, time;
};
struct cmp {
	bool operator()(build b1, build b2) {
		if (b1.time != b2.time)
			return b1.time > b2.time;
		return b1.idx > b2.idx;
	}
};

int N, indegree[501];
build bd[501];
vector<int> vec[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int a;
	for (int i = 1; i <= N; ++i) {
		cin >> a;
		bd[i].time = a;
		while (1) {
			cin >> a;
			if (a == -1) break;
			indegree[i]++;
			vec[a].push_back(i);
		}
	}

	priority_queue<build, vector<build>, cmp> pq;
	for (int i = 1; i <= N; ++i) {
		if (!indegree[i]) pq.push({ i,bd[i].time });
	}

	while (!pq.empty()) {
		int cur = pq.top().idx;
		pq.pop();
		for (int n : vec[cur]) {
			indegree[n]--;
			if (!indegree[n]) {
				bd[n].time += bd[cur].time;
				pq.push({ n,bd[n].time });
			}
		}
	}

	for (int i = 1; i <= N; ++i) cout << bd[i].time << '\n';

	return 0;
}