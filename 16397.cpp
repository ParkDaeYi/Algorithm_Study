#include <iostream>
#include <queue>
using namespace std;

int n, t, g, cache[100000];

int bfs();

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> t >> g;
	int ans = bfs();
	ans == -1 ? cout << "ANG" : cout << ans;
	return 0;
}

int bfs() {
	queue<int> q;
	q.push(n);
	cache[n] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cache[cur] - 1 > t) return -1;
		if (cur == g) return cache[cur] - 1;
		int a = cur + 1;
		if (!cache[a]) {
			cache[a] = cache[cur] + 1;
			q.push(a);
		}
		int b = cur * 2;
		if (b > 99999) continue;
		int tmp = b, m = 1;
		while (tmp) {
			tmp /= 10;
			m *= 10;
		}
		m /= 10;
		b -= m;
		if (b < 100000 && !cache[b]) {
			cache[b] = cache[cur] + 1;
			q.push(b);
		}
	}
	return -1;
}