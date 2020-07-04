#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

int n, m, k;
llt seg[1 << 21];

llt query(int node, int start, int end, int left, int right) {
	// node: 세그먼트 트리 인덱스, start, end: 세그먼트 트리 범위, left, right: 찾아야 할 범위
	if (left <= start && end <= right) return seg[node];	// 해당 범위일 경우 return
	if (end < left || right < start) return 0;	// 범위를 벗어날 경우 return
	int mid = (start + end) >> 1;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	const int sz = pow(2, (int)log2(n - 1) + 1);	// 포화이진 트리 사이즈
	for (int i = 0;i < n;++i) cin >> seg[sz + i];	// 초기 값 입력
	for (int i = sz - 1;i > 0;--i) seg[i] = seg[i * 2] + seg[i * 2 + 1];	// 세그먼트 트리 갱신
	m += k;
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 1) {
			int diff = c - seg[sz + b - 1];	// 수정해야 하는 값
			for (int node = b + sz - 1;node > 0;node /= 2) seg[node] += diff;	// 세그먼트 트리 갱신
		}
		else cout << query(1, 1, sz, b, c) << '\n';
	}
	return 0;
}