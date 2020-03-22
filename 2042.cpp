#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

llt seg[1 << 21];
int n, m, k, sz;

llt sum(int, int, int, int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	sz = pow(2, (int)log2(n) + 1);
	for (int i = 0; i < n; ++i) cin >> seg[i + sz];
	for (int i = sz - 1; i > 0; --i) seg[i] = seg[i * 2] + seg[i * 2 + 1];
	for (int i = 0; i < m + k; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			llt node = sz + b - 1;
			int diff = c - seg[node];
			seg[node] = c;
			for (node /= 2; node > 0; node /= 2) seg[node] += diff;
		}
		else cout << sum(1, 1, sz, b, c) << '\n';	
	}
	return 0;
}

llt sum(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return seg[node];
	if (end < left || right < start) return 0;
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}