#include <iostream>
#include <vector>
#define MAX_N 100001
using namespace std;

int n, m, seg[MAX_N * 4], lazy[MAX_N * 4], number[MAX_N], child[MAX_N], w[MAX_N], order[MAX_N], sz;
vector<int> p[MAX_N];
bool used[MAX_N];

int range(int idx) {
	used[idx] = 1;
	int ch = 0;
	for (int nxt : p[idx]) {
		if (used[nxt]) continue;
		ch += range(nxt);
	}
	number[idx] = ++sz;
	child[idx] = ch;
	order[sz] = w[idx];
	return ch + 1;
}

void init(int node, int s, int e) {
	if (s == e) {
		seg[node] = order[s];
		return;
	}
	int mid = (s + e) >> 1;
	init(node * 2, s, mid);
	init(node * 2 + 1, mid + 1, e);
	seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
}

void update_lazy(int node, int s, int e) {
	if (!lazy[node]) return;
	seg[node] ^= lazy[node] * ((e - s + 1) % 2);
	if (s != e) {
		lazy[node * 2] ^= lazy[node];
		lazy[node * 2 + 1] ^= lazy[node];
	}
	lazy[node] = 0;
}

void update_range(int node, int s, int e, int left, int right, int val) {
	update_lazy(node, s, e);
	if (e < left || right < s) return;
	if (left <= s && e <= right) {
		seg[node] ^= val * ((e - s + 1) % 2);
		if (s != e) {
			lazy[node * 2] ^= val;
			lazy[node * 2 + 1] ^= val;
		}
		return;
	}
	int mid = (s + e) >> 1;
	update_range(node * 2, s, mid, left, right, val);
	update_range(node * 2 + 1, mid + 1, e, left, right, val);
	seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
}

int query(int node, int s, int e, int left, int right) {
	update_lazy(node, s, e);
	if (e < left || right < s) return 0;
	if (left <= s && e <= right) return seg[node];
	int mid = (s + e) >> 1;
	return query(node * 2, s, mid, left, right) ^ query(node * 2 + 1, mid + 1, e, left, right);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1, x, y;i < n;++i) {
		cin >> x >> y;
		p[x].push_back(y);
		p[y].push_back(x);
	}
	for (int i = 1;i <= n;++i) cin >> w[i];	
	range(1);
	init(1, 1, n);
	while (m--) {
		int t, x, y;
		cin >> t >> x;
		if (t == 1) cout << query(1, 1, n, number[x] - child[x], number[x]) << '\n';
		else {
			cin >> y;
			update_range(1, 1, n, number[x] - child[x], number[x], y);
		}
	}
	return 0;
}