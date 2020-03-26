#include <iostream>
#include <vector>
#define MAX_N 500001
using namespace std;
typedef long long int llt;

int n, m, l[MAX_N], r[MAX_N], order[MAX_N], money[MAX_N];
llt seg[MAX_N * 4], lazy[MAX_N * 4];
vector<int> p[MAX_N];

void range(int idx, int& c) {
	l[idx] = ++c;
	for (int nxt : p[idx]) range(nxt, c);
	r[idx] = c;
}

void init(int node, int start, int end) {
	if (start == end) {
		seg[node] = order[start];
		return;
	}
	int mid = (start + end) >> 1;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
}

void update_lazy(int node, int start, int end) {
	if (!lazy[node]) return;
	seg[node] += lazy[node];
	if (start != end) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update_range(int node, int start, int end, int left, int right, int val) {
	update_lazy(node, start, end);
	if (end < left || right < start) return;
	if (left <= start && end <= right) {
		seg[node] += val;
		if (start != end) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	int mid = (start + end) >> 1;
	update_range(node * 2, start, mid, left, right, val);
	update_range(node * 2 + 1, mid + 1, end, left, right, val);
}

llt query(int node, int start, int end, int idx) {
	update_lazy(node, start, end);
	if (end < idx || idx < start) return 0;
	if (start == end) return seg[node];
	int mid = (start + end) >> 1;
	return query(node * 2, start, mid, idx) + query(node * 2 + 1, mid + 1, end, idx);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cin >> money[1];
	for (int i = 2, x;i < n + 1;++i) {
		cin >> money[i] >> x;
		p[x].push_back(i);
	}
	int c = 0;
	range(1, c);
	for (int i = 1;i < n + 1;++i) order[l[i]] = money[i];
	init(1, 1, n);
	while (m--) {
		char s;
		int a, b;
		cin >> s;
		if (s == 'p') {
			cin >> a >> b;
			update_range(1, 1, n, l[a] + 1, r[a], b);
		}
		else if (s == 'u') {
			cin >> a;
			cout << query(1, 1, n, l[a]) << '\n';
		}
	}
	return 0;
}