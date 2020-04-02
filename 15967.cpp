#include <iostream>
#define MAX_N 1000001
using namespace std;
typedef long long int llt;

int n, q1, q2;
llt seg[MAX_N * 4], lazy[MAX_N * 4], arr[MAX_N];

void init(int node, int s, int e) {
	if (s == e) {
		seg[node] = arr[s];
		return;
	}
	int mid = (s + e) >> 1;
	init(node * 2, s, mid);
	init(node * 2 + 1, mid + 1, e);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

void update_lazy(int node, int s, int e) {
	if (!lazy[node]) return;
	seg[node] += (e - s + 1) * lazy[node];
	if (s != e) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update_range(int node, int s, int e, int left, int right, int val) {
	update_lazy(node, s, e);
	if (e < left || right < s) return;
	if (left <= s && e <= right) {
		seg[node] += (e - s + 1) * val;
		if (s != e) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	int mid = (s + e) >> 1;
	update_range(node * 2, s, mid, left, right, val);
	update_range(node * 2 + 1, mid + 1, e, left, right, val);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

llt query(int node, int s, int e, int left, int right) {
	update_lazy(node, s, e);
	if (e < left || right < s) return 0;
	if (left <= s && e <= right) return seg[node];
	int mid = (s + e) >> 1;
	return query(node * 2, s, mid, left, right) + query(node * 2 + 1, mid + 1, e, left, right);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> q1 >> q2;
	for (int i = 1, num;i < n + 1;++i) cin >> arr[i];
	init(1, 1, n);
	int m = q1 + q2;
	while (m--) {
		int op, x, y, z;
		cin >> op;
		if (op == 1) {
			cin >> x >> y;
			cout << query(1, 1, n, x, y) << '\n';
		}
		else {
			cin >> x >> y >> z;
			update_range(1, 1, n, x, y, z);
		}
	}
	return 0;
}