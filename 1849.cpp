#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

llt seg[1 << 21];
int ans[100001], n;

llt query(int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	const int sz = pow(2, (int)log2(n - 1) + 1);
	for (int i = 0; i < n; ++i) seg[i + sz] = 1;
	for (int i = sz - 1; i > 0; --i) seg[i] = seg[i * 2] + seg[i * 2 + 1];
	for (int i = 1, num; i <= n; ++i) {
		cin >> num;
		int idx = query(1, 1, sz, num + 1);
		ans[idx] = i;
		idx += sz - 1;
		seg[idx] = 0;
		for (idx /= 2; idx > 0; idx /= 2) seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
	}
	for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
	return 0;
}

llt query(int node, int start, int end, int idx) {
	if (start == end) return start;
	int mid = (start + end) / 2;
	if (seg[node * 2] < idx) return query(node * 2 + 1, mid + 1, end, idx - seg[node * 2]);
	return query(node * 2, start, mid, idx);
}