#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long int llt;
typedef pair<int, int> pii;

llt seg[1 << 21];
pii arr[100001];
int n;

void update_tree(int, int);
llt sum(int, int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	const int sz = pow(2, (int)log2(n) + 1);
	for (int i = 0; i < n; ++i) seg[sz + i] = 1;
	for (int i = sz - 1; i > 0; --i) seg[i] = seg[i * 2] + seg[i * 2 + 1];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}
	sort(arr, arr + n);
	for (int i = 0, L = 0, R = n - 1; i < n; ++i) {
		if (i % 2) {
			cout << sum(1, 1, sz, arr[n - 1 - i / 2].second + 1, n) << '\n';
			update_tree(arr[n - 1 - i / 2].second + sz - 1, 0);
		}
		else {
			cout << sum(1, 1, sz, 1, arr[i / 2].second - 1) << '\n';
			update_tree(arr[i / 2].second + sz - 1, 0);
		}
	}
	return 0;
}

void update_tree(int idx, int diff) {
	diff = diff - seg[idx];
	seg[idx] = 0;
	for (idx /= 2; idx > 0; idx /= 2) seg[idx] += diff;
}

llt sum(int itr, int start, int end, int left, int right) {
	if (left <= start && end <= right) return seg[itr];
	if (end < left || right < start) return 0;
	int mid = (start + end) / 2;
	return sum(itr * 2, start, mid, left, right) + sum(itr * 2 + 1, mid + 1, end, left, right);
}