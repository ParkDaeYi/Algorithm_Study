#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 1e9+1
using namespace std;

int n, m, seg[1 << 21];

int find_min(int, int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	const int sz = pow(2, (int)log2(n - 1) + 1);
	for (int i = 0; i < n; ++i) cin >> seg[i + sz];
	for (int i = n; i < sz; ++i) seg[i + sz] = MAX;
	for (int i = sz - 1; i > 0; --i) seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << find_min(1, 1, sz, a, b) << '\n';
	}
	return 0;
}

int find_min(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return seg[node];
	if (end < left || right < start) return MAX;
	int mid = (start + end) / 2;
	return min(find_min(node * 2, start, mid, left, right), find_min(node * 2 + 1, mid + 1, end, left, right));
}