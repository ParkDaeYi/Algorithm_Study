#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

int n, m;
llt seg[1 << 21], lazy[1 << 21];

void update_lazy(int, int, int);
void update_range(int, int, int, int, int, llt);
llt sum(int, int, int, int, int);
inline void swap_int(int& a, int& b) {
	int t = a; a = b; b = t; return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	const int sz = pow(2, (int)log2(n - 1) + 1);
	for (int i = 0; i < n; ++i) cin >> seg[i + sz];
	for (int i = sz - 1; i > 0; --i) seg[i] = seg[i * 2] ^ seg[i * 2 + 1];
	cin >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			llt d;
			cin >> d;
			if (b > c) swap_int(b, c);
			update_range(1, 0, sz - 1, b, c, d);
		}
		else {
			if (b > c) swap_int(b, c);
			cout << sum(1, 0, sz - 1, b, c) << '\n';
		}
	}
	return 0;
}

void update_lazy(int node, int start, int end) {
	if (!lazy[node]) return;
	seg[node] ^= lazy[node] * ((end - start + 1) % 2);
	if (start != end) {
		lazy[node * 2] ^= lazy[node];
		lazy[node * 2 + 1] ^= lazy[node];
	}
	lazy[node] = 0;
	return;
}

void update_range(int node, int start, int end, int left, int right, llt val) {
	update_lazy(node, start, end);
	if (end < left || right < start) return;
	if (left <= start && end <= right) {
		seg[node] ^= val * ((end - start + 1) % 2);
		if (start != end) {
			lazy[node * 2] ^= val;
			lazy[node * 2 + 1] ^= val;
		}
		return;
	}
	int mid = (start + end) / 2;
	update_range(node * 2, start, mid, left, right, val);
	update_range(node * 2 + 1, mid + 1, end, left, right, val);
	seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
	return;
}

llt sum(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (left <= start && end <= right) return seg[node];
	if (end < left || right < start) return 0;
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) ^ sum(node * 2 + 1, mid + 1, end, left, right);
}