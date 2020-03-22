#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

llt seg[1 << 21];
int n, q;

llt sum(int, int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	const int sz = pow(2, (int)log2(n) + 1);
	while (q--) {
		int t, d, m;
		cin >> t >> d >> m;
		if (t == 1) {
			int itr = sz + d - 1;
			llt diff = seg[itr] + m;
			seg[itr] = diff;
			for (itr /= 2; itr > 0; itr /= 2) seg[itr] = seg[itr * 2] + seg[itr * 2 + 1];
		}
		else cout << sum(1, 1, sz, d, m) << '\n';
	}
	return 0;
}

llt sum(int itr, int start, int end, int left, int right) {
	if (left <= start && end <= right) return seg[itr];
	if (end < left || right < start) return 0;
	int mid = (start + end) / 2;
	return sum(itr * 2, start, mid, left, right) + sum(itr * 2 + 1, mid + 1, end, left, right);
}