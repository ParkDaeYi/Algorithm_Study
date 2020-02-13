#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int ans, n, l, p, idx;
pii info[10000];
priority_queue<int, vector<int>, less<int>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> info[i].first >> info[i].second;
	sort(info, info + n);
	cin >> l >> p;
	idx = 1; pq.push(info[0].second);
	while (p < l) {
		while (info[idx].first <= p && idx < n) {
			pq.push(info[idx].second);
			++idx;
		}
		++ans;
		if (pq.empty()) break;
		p += pq.top();
		pq.pop();
	}
	if (p < l) cout << -1;
	else cout << ans;
	return 0;
}