#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

int n, m;
llt seg[1 << 21];

void query(int node, int s, int e, int l, int r, int val) {
	if (e < l || r < s) return;
	if (l <= s && e <= r) {
		seg[node] += val;
		return;
	}
	int mid = (s + e) >> 1;
	query(node * 2, s, mid, l, r, val);
	query(node * 2 + 1, mid + 1, e, l, r, val);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	const int sz = pow(2, (int)log2(n - 1) + 1);
	for (int i = 0;i < n;++i) cin >> seg[sz + i];
	cin >> m;
	while (m--) {
		int op, x, y, z;
		cin >> op >> x;
		if (op == 1) {
			cin >> y >> z;
			query(1, 1, sz, x, y, z);
		}
		else {
			int node = sz + x - 1;
			llt ans = seg[node];
			for (node /= 2;node > 0;node /= 2) ans += seg[node];
			cout << ans << '\n';
		}
	}
	return 0;
}