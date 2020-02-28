#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX_N 5000
#define MAX_L 20000
using namespace std;

class INFO {
public:
	int x, y1, y2, val;
	INFO(int x = 0, int y1 = 0, int y2 = 0, int val = 0) :x(x), y1(y1), y2(y2), val(val) {}
};

int seg[1 << 21], cnt[1 << 21], n, arr[MAX_N][4], ans;
INFO info[MAX_N + MAX_N];

inline void swap_int(int& a, int& b) {
	int t = a; a = b; b = t; return;
}
void solve();
void update_tree(int, int, int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j) cin >> arr[i][j], arr[i][j] += 1e4;
		if (arr[i][0] > arr[i][2]) swap_int(arr[i][0], arr[i][2]);
		if (arr[i][1] > arr[i][3]) swap_int(arr[i][1], arr[i][3]);
	}
	solve();
	for (int i = 0; i < n; ++i) swap_int(arr[i][0], arr[i][1]), swap_int(arr[i][2], arr[i][3]);
	solve();
	cout << ans;
	return 0;
}

void solve() {
	for (int i = 0; i < n; ++i) {
		info[i] = INFO(arr[i][0], arr[i][1], arr[i][3] - 1, 1);
		info[i + n] = INFO(arr[i][2], arr[i][1], arr[i][3] - 1, -1);
	}
	sort(info, info + n + n, [](const INFO& a, const INFO& b) {
		if (a.x == b.x) return a.val > b.val;
		return a.x < b.x;
	});
	const int sz = pow(2, (int)log2(MAX_L - 1) + 1);
	for (int i = 0, prev = 0; i < n + n; ++i) {
		update_tree(1, 0, sz - 1, info[i].y1, info[i].y2, info[i].val);
		ans += abs(seg[1] - prev);
		prev = seg[1];
	}
}

void update_tree(int node, int start, int end, int left, int right, int val) {
	if (end < left || right < start) return;
	if (left <= start && end <= right) cnt[node] += val;
	else {
		int mid = (start + end) >> 1;
		update_tree(node * 2, start, mid, left, right, val);
		update_tree(node * 2 + 1, mid + 1, end, left, right, val);
	}
	if (cnt[node]) seg[node] = end - start + 1;
	else seg[node] = start == end ? 0 : seg[node * 2] + seg[node * 2 + 1];
}