#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

int n, q;
llt seg[1 << 21];

llt query(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return seg[node];
	if (end < left || right < start) return 0;
	int mid = (start + end) >> 1;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> q;
	const int sz = pow(2, (int)log2(n) + 1);	// 세그먼트 트리 사이즈
	for (int i = 0; i < n; ++i) cin >> seg[sz + i];	
	for (int i = sz - 1; i > 0; --i) seg[i] = seg[i * 2] + seg[i * 2 + 1];	// 갱신
	int a, b, c, d;
	while (q--) {
		cin >> a >> b >> c >> d;
		if (a > b) swap(a, b);	// a가 b보다 크면 안되니까 swap
		cout << query(1, 1, sz, a, b) << '\n';
		int node = sz + c - 1;	// 수정해야 할 인덱스 번호
		llt diff = d - seg[node];	// 갱신해야 할 값
		for (; node > 0; node /= 2) seg[node] += diff;	// 세그먼트 트리 갱신
	}
	return 0;
}