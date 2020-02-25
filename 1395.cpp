#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

llt seg[1 << 21], lazy[1 << 21];
int n, m;

void update_lazy(int, int, int);
int update_range(int, int, int, int, int);
llt sum(int, int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	const int sz = pow(2, (int)log2(n - 1) + 1);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a) cout << sum(1, 1, sz, b, c) << '\n';
		else update_range(1, 1, sz, b, c);
	}
	return 0;
}

void update_lazy(int node, int start, int end) {
	if (!lazy[node]) return;
	seg[node] = (end - start + 1) - seg[node];
	if (start != end) {
		lazy[node * 2] = !lazy[node * 2];
		lazy[node * 2 + 1] = !lazy[node * 2 + 1];
	}
	lazy[node] = 0;
	return;
}

int update_range(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (end < left || right < start) return seg[node];
	if (left <= start && end <= right) {
		seg[node] = (end - start + 1) - seg[node];
		if (start != end) {
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		return seg[node];
	}
	int mid = (start + end) / 2;
	return seg[node] = update_range(node * 2, start, mid, left, right) + update_range(node * 2 + 1, mid + 1, end, left, right);
}

llt sum(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) return seg[node];
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}