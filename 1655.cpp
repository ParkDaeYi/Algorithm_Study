#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int n;
priority_queue <int, vector<int>, less<int> > max_pq;
priority_queue<int, vector<int>, greater<int> > min_pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;

		if (i % 2 == 0) max_pq.push(tmp);
		else min_pq.push(tmp);

		if (!min_pq.empty() && max_pq.top() > min_pq.top()) {
			int t = max_pq.top();
			max_pq.pop(); max_pq.push(min_pq.top());
			min_pq.pop(); min_pq.push(t);
		}

		cout << max_pq.top() << "\n";
	}
	return 0;
}