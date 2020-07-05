#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	priority_queue<int, vector<int>, less<int>> pq;	// 내림차순으로 정렬
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		if (x) pq.push(x);
		else {
			cout << (pq.empty() ? 0 : pq.top()) << '\n';
			if (!pq.empty()) pq.pop();
		}
	}
	return 0;
}