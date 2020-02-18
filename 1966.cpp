#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		int n, m, idx = 0;
		cin >> n >> m;
		queue<pii> q;
		priority_queue<int, vector<int>, less<int>> pq;
		for (int i = 0; i < n; ++i) {
			int num;
			cin >> num;
			q.push(make_pair(num, i));
			pq.push(num);
		}
		while (!q.empty()) {
			if (pq.top() == q.front().first) {
				++idx;
				if (q.front().second == m) {
					cout << idx << '\n'; break;
				}
				q.pop();
				pq.pop();
			}
			else if (pq.top() != q.front().first) {
				q.push(q.front());
				q.pop();
			}
		}
	}
	return 0;
}

