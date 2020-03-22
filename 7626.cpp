#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX_N 200000
using namespace std;
typedef long long int llt;

class info {
public:
	int x, y1, y2, val;
	info(int x = 0, int y1 = 0, int y2 = 0, int v = 0) :x(x), y1(y1), y2(y2), val(v) {}
}pos[MAX_N + MAX_N];
int n, arrY[MAX_N + MAX_N];
llt seg[1 << 21], cnt[1 << 21];

void update_tree(int, int, int, int, int, int);
int lower_bd(int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0, a, b, c, d; i < n; ++i) {
		cin >> a >> b >> c >> d;
		pos[i] = info(a, c, d, 1);
		pos[i + n] = info(b, c, d, -1);
		arrY[i] = c;
		arrY[i + n] = d;
	}
	sort(arrY, arrY + n + n);
	int szY = unique(arrY, arrY + n + n) - arrY;
	sort(pos, pos + n + n, [](const info& a, const info& b) {
		return a.x < b.x;
	});
	const int sz = pow(2, (int)log2(n + n - 1) + 1);
	llt ans = 0;
	for (int i = 0, prev; i < n + n; ++i) {
		if (i) ans += (pos[i].x - prev) * seg[1];
		update_tree(1, 0, sz - 1, lower_bd(0, szY, pos[i].y1), lower_bd(0, szY, pos[i].y2) - 1, pos[i].val);
		prev = pos[i].x;
	}
	cout << ans;
	return 0;
}

void update_tree(int node, int start, int end, int left, int right, int val) {
	if (end < left || right < start) return;
	if (left <= start && end <= right) cnt[node] += val;
	else {
		int mid = (start + end) >> 1;
		update_tree(node * 2, start, mid, left, right, val);
		update_tree(node * 2 + 1, mid + 1, end, left, right, val);
	}
	if (cnt[node]) seg[node] = arrY[end + 1] - arrY[start];
	else seg[node] = start == end ? 0 : seg[node * 2] + seg[node * 2 + 1];
}

int lower_bd(int left, int right, int target) {
	int mid;
	while (left < right) {
		mid = (left + right) >> 1;
		if (arrY[mid] < target) left = mid + 1;
		else right = mid;
	}
	return right;
}