#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

int n, fac[1000001], fac_idx[1000001];
llt seg[1 << 21], ans;

llt sum(int, int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	const int sz = pow(2, (int)log2(n - 1) + 1);
	int tmp;
	for (int i = 1; i <= n; ++i) {
		cin >> tmp;
		fac[tmp] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> tmp;
		fac_idx[i] = fac[tmp];
	}
	for (int i = 1; i <= n; ++i) {
		ans += sum(1, 1, sz, fac_idx[i] + 1, n);
		int node = fac_idx[i] + sz - 1;
		seg[node] = 1;
		for (node /= 2; node > 0; node /= 2) seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
	cout << ans;
	return 0;
}

llt sum(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return seg[node];
	if (end < left || right < start) return 0;
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}