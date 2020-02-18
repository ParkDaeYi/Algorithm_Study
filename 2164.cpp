#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) q.push(i);
	while (1) {
		if (q.size() == 1) break;
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
	return 0;
}