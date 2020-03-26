#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

int n, m;
llt seg[1 << 21];

void query(int node, int start, int end, int left, int right, llt val) {
	if (end < left || right < start) return;
	if (left <= start && end <= right) {
		seg[node] ^= val; 
		return;
	}
	int mid = (start + end) >> 1;
	query(node * 2, start, mid, left, right, val);
	query(node * 2 + 1, mid + 1, end, left, right, val);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	const int sz = pow(2, (int)log2(n) + 1);
	for (int i = 0;i < n;++i) cin >> seg[sz + i];
	cin >> m;
	while (m--) {
		int a, b, c, d;
		cin >> a >> b;
		if (a == 1) {
			cin >> c >> d;
			query(1, 1, sz, b + 1, c + 1, d);
		}
		else {
			int node = sz + b;
			int ans = seg[node];
			for (node /= 2;node > 0;node /= 2) ans ^= seg[node];
			cout << ans << '\n';
		}
	}
	return 0;
}