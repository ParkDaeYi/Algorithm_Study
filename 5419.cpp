#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
typedef long long int llt;

int t, reY[75000], n;
llt seg[1 << 21];
pii pos[75000];

llt sum(int, int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> pos[i].first >> pos[i].second;
		sort(pos, pos + n, [](const pii& p1, const pii& p2) {
			return p1.second < p2.second;
		});
		int h = 1;
		for (int i = 0; i < n; ++i) {
			if (i > 0 && pos[i - 1].second < pos[i].second) h++;;
			reY[i] = h;
		}
		for (int i = 0; i < n; ++i) pos[i].second = reY[i];
		sort(pos, pos + n, [](const pii& p1, const pii& p2) {
			if (p1.first == p2.first) return p1.second > p2.second;
			return p1.first < p2.first;
		});
		llt ans = 0;
		const int sz = pow(2, (int)log2(n - 1) + 1);
		for (int i = 0; i < n; ++i) {
			ans += sum(1, 1, sz, pos[i].second, n);
			int node = pos[i].second + sz - 1;
			seg[node]++;
			for (node /= 2; node > 0; node /= 2) seg[node]++;
		}
		cout << ans << '\n';
		fill(seg, seg + sz + h, 0);
	}
	return 0;
}

llt sum(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return seg[node];
	if (end < left || right < start) return 0;
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}