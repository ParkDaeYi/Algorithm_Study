#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

const llt MOD = 1e9 + 7;
llt seg[1 << 21];
int n, m, k;

llt mul(int, int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	const int sz = pow(2, (int)log2(n) + 1);

	for (int i = 0; i < n; ++i) cin >> seg[sz + i];
	for (int i = n; i < sz; ++i) seg[sz + i] = 1;
	for (int i = sz - 1; i > 0; --i) seg[i] = (seg[i * 2] * seg[i * 2 + 1]) % MOD;
	for (int i = 0; i < m + k; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			int node = sz + b - 1;
			seg[node] = c;
			for (node /= 2; node > 0; node /= 2) seg[node] = (seg[node * 2] * seg[node * 2 + 1]) % MOD;
		}
		else cout << mul(1, 1, sz, b, c) << '\n';
	}
	return 0;
}

llt mul(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return seg[node];
	if (end < left || right < start) return 1;
	int mid = (start + end) / 2;
	return (mul(node * 2, start, mid, left, right) * mul(node * 2 + 1, mid + 1, end, left, right)) % MOD;
}