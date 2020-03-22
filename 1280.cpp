#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

const int MOD = 1000000007;
const int MAX_NODE = 200000;
const int sz = pow(2, (int)log2(MAX_NODE - 1) + 1);
int n;
llt seg[1 << 21], cnt[1 << 21], ans = 1;

void update_tree(int, int);
llt query_sum(int, int, int, int, int);
llt query_cnt(int, int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int num;
	cin >> num;
	update_tree(num, num);
	for (int i = 1; i < n; ++i) {
		cin >> num;
		llt left = query_cnt(1, 0, sz, 0, num) * num - query_sum(1, 0, sz, 0, num);
		llt right = query_sum(1, 0, sz, num + 1, sz) - query_cnt(1, 0, sz, num + 1, sz) * num;
		ans = ((left + right) % MOD * ans) % MOD;
		update_tree(num, num);
	}
	cout << ans;
	return 0;
}

void update_tree(int idx, int val) {
	idx += sz;
	seg[idx] += val;
	cnt[idx]++;
	for (idx /= 2; idx > 0; idx /= 2) {
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
		cnt[idx] = cnt[idx * 2] + cnt[idx * 2 + 1];
	}
	return;
}

llt query_sum(int itr, int start, int end, int left, int right) {
	if (left <= start && end <= right) return seg[itr];
	if (end < left || right < start) return 0;
	int mid = (start + end) / 2;
	return query_sum(itr * 2, start, mid, left, right) + query_sum(itr * 2 + 1, mid + 1, end, left, right);
}

llt query_cnt(int itr, int start, int end, int left, int right) {
	if (left <= start && end <= right) return cnt[itr];
	if (end < left || right < start) return 0;
	int mid = (start + end) / 2;
	return query_cnt(itr * 2, start, mid, left, right) + query_cnt(itr * 2 + 1, mid + 1, end, left, right);
}