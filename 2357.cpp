#include <iostream>
#include <algorithm>
#include <cmath>
#define INF 1e9+1
using namespace std;

int min_seg[1 << 21], max_seg[1 << 21];
int n, m;

int retMax(int, int, int, int, int);
int retMin(int, int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	const int sz = pow(2, (int)log2(n) + 1);
	for (int i = 0; i < n; ++i) {
		cin >> min_seg[sz + i];
		max_seg[sz + i] = min_seg[sz + i];
	}
	for (int i = n; i < sz; ++i) min_seg[sz + i] = INF;
	for (int i = sz - 1; i > 0; --i) {
		min_seg[i] = min(min_seg[i * 2], min_seg[i * 2 + 1]);
		max_seg[i] = max(max_seg[i * 2], max_seg[i * 2 + 1]);
	}

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		cout << retMin(1, 1, sz, a, b) << ' ' << retMax(1, 1, sz, a, b) << '\n';
	}
	return 0;
}

int retMax(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return max_seg[node];
	if (end < left || right < start) return 0;
	int mid = (start + end) / 2;
	return max(retMax(node * 2, start, mid, left, right), retMax(node * 2 + 1, mid + 1, end, left, right));
}

int retMin(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return min_seg[node];
	if (end < left || right < start) return INF;
	int mid = (start + end) / 2;
	return min(retMin(node * 2, start, mid, left, right), retMin(node * 2 + 1, mid + 1, end, left, right));
}