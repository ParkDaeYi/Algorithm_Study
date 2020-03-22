#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d, cache[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> f >> s >> g >> u >> d;
	// f: max, s: cur, g: dest, u: up, d: down
	if (g > s || g < s) {
		if ((g > s && !u) || (g < s && !d)) {
			cout << "use the stairs";
			return 0;
		}
		int dir[2] = { u,-d };
		queue<int> q;
		q.push(s);
		cache[s] = 1;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (cur == g) break;
			for (int i = 0; i < 2; ++i) {
				int next = cur + dir[i];
				if (next < 1 || next > f) continue;
				if (cache[next]) continue;
				q.push(next);
				cache[next] = cache[cur] + 1;
			}
		}
		cache[g] ? cout << cache[g] - 1 : cout << "use the stairs";
		return 0;
	}
	else {
		cout << 0;
		return 0;
	}
}