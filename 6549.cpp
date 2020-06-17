#include <iostream>
#define MAX_N 100001
using namespace std;
typedef long long int llt;

int n;
llt seg[MAX_N * 4], arr[MAX_N];

void init(int node, int s, int e) {
	if (s == e) seg[node] = s;
	else {
		int mid = (s + e) >> 1;
		init(node * 2, s, mid);
		init(node * 2 + 1, mid + 1, e);
		seg[node] = arr[seg[node * 2]] < arr[seg[node * 2 + 1]] ? seg[node * 2] : seg[node * 2 + 1];
	}
}

int query(int node, int s, int e, int l, int r) {
	if (r < s || e < l) return -1;
	if (l <= s && e <= r) return seg[node];
	int mid = (s + e) >> 1;
	int left = query(node * 2, s, mid, l, r), right = query(node * 2 + 1, mid + 1, e, l, r);
	if (left == -1) return right;
	else if (right == -1) return left;
	else if (arr[left] < arr[right]) return left;
	else return right;
}

llt getMaxArea(int s, int e) {
	int idx = query(1, 0, n - 1, s, e);
	llt ret = (e - s + 1) * arr[idx];
	if (s < idx) {
		llt tmp = getMaxArea(s, idx - 1);
		ret = ret < tmp ? tmp : ret;
	}
	if (idx < e) {
		llt tmp = getMaxArea(idx + 1, e);
		ret = ret < tmp ? tmp : ret;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (cin >> n) {
		if (!n) break;
		for (int i = 0; i < n; ++i) cin >> arr[i];
		init(1, 0, n - 1);
		cout << getMaxArea(0, n - 1) << '\n';
	}
	return 0;
}