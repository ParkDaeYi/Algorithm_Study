#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

int n, m;
llt seg[1 << 21];

inline void swap_int(int& a, int& b) {
	int t = a; a = b; b = t; return;
}
llt sum(int, int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	const int sz = pow(2, (int)log2(n) + 1);
	while (m--) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t) {
			int itr = sz + a - 1;
			llt diff = b - seg[itr];
			seg[itr] = b;
			for (itr /= 2; itr > 0; itr /= 2) seg[itr] += diff;
		}
		else {
			if (a > b) swap_int(a, b);
			cout << sum(1, 1, sz, a, b) << '\n';
		}
	}
	return 0;
}

llt sum(int itr, int start, int end, int left, int right) {
	if (left <= start && end <= right) return seg[itr];
	if (end < left || right < start) return 0;
	int mid = (start + end) / 2;
	return sum(itr * 2, start, mid, left, right) + sum(itr * 2 + 1, mid + 1, end, left, right);
}