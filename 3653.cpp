#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

int n, m, t, dvd[100002];
llt seg[1 << 21];

void update_seg(int, int);
llt sum(int, int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		const int sz = pow(2, (int)log2(n + m - 1) + 1);
		for (int i = 1; i <= n; ++i) {
			dvd[i] = i + m;
			seg[i + m + sz - 1] = 1;
		}
		for (int i = sz - 1; i > 0; --i) seg[i] = seg[i * 2] + seg[i * 2 + 1];
		for (int i = 0; i < m; ++i) {
			int num;
			cin >> num;
			cout << sum(1, 1, sz, 1, dvd[num] - 1) << ' ';
			update_seg(dvd[num] + sz - 1, 0);
			dvd[num] = m - i;
			update_seg(dvd[num] + sz - 1, 1);
		}
		fill(seg, seg + sz + n + m, 0);
		cout << '\n';
	}
	return 0;
}

void update_seg(int idx,int val) {
	int diff = val - seg[idx];
	seg[idx] = val;
	for (idx /= 2; idx > 0; idx /= 2) seg[idx] += diff;
	return;
}

llt sum(int itr, int start, int end, int left, int right) {
	if (left <= start && end <= right) return seg[itr];
	if (end < left || right < start) return 0;
	int mid = (start + end) / 2;
	return sum(itr * 2, start, mid, left, right) + sum(itr * 2 + 1, mid + 1, end, left, right);
}