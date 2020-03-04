#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, seg[1 << 21];
pii arr[500000];

int sum(int, int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i) arr[i].first = i + 1;
	sort(arr, arr + n, [](const pii& a, const pii& b) {
		return a.second < b.second;
	});
	const int sz = pow(2, (int)log2(n - 1) + 1);
	for (int i = 0; i < n; ++i) {
		cout << sum(1, 1, sz, arr[i].first, n) + 1 << '\n';
		int node = arr[i].first + sz - 1;
		seg[node] += 1;
		for (node /= 2; node > 0; node /= 2) seg[node] += 1;
	}
	return 0;
}

int sum(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return seg[node];
	if (end < left || right < start) return 0;
	int mid = (start + end) >> 1;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}