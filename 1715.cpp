#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int n, ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		pq.push(num);
	}

	while (1) {
		int first = pq.top();
		pq.pop();
		if (!pq.empty()) {
			int second = pq.top();
			pq.pop();
			pq.push(first + second);
			ans += first + second;
		}
		else {
			cout << ans;
			return 0;
		}
	}
}
