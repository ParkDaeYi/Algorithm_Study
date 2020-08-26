#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define N 100001
#pragma warning(disable:4996)
using namespace std;
typedef pair<int, int> pii;

int n, xarr[N], yarr[N], ans, now;
vector<pii> v;

int main() {
	scanf("%d\n", &n);
	for (int i = 0;i < n;++i) scanf("%d %d", xarr + i, yarr + i);
	xarr[n] = xarr[0], yarr[n] = yarr[0];

	for (int i = 0;i < n;++i) if (yarr[i] == yarr[i + 1]) {
		int a = xarr[i], b = xarr[i + 1];
		if (a > b) swap(a, b);
		v.emplace_back(a, 1);
		v.emplace_back(b, -1);
	}
	sort(v.begin(), v.end());
	for (pii i : v) now += i.second, ans = max(ans, now);

	v.clear();
	for (int i = 0;i < n;++i) if (xarr[i] == xarr[i + 1]) {
		int a = yarr[i], b = yarr[i + 1];
		if (a > b) swap(a, b);
		v.emplace_back(a, 1);
		v.emplace_back(b, -1);
	}
	sort(v.begin(), v.end());
	for (pii i : v) now += i.second, ans = max(ans, now);

	printf("%d", ans);
	return 0;
}

// 뻘짓...
int n;
vector<pii> arr;

struct Segment {
	int n, ans = 0;
	vector<int> seg, lazy, srt;
	Segment(int len = 0) {
		n = len;
		seg.resize(n * 4, 0);
		lazy.resize(n * 4, 0);
	}

	int lower(int left, int right, int t) {
		while (left < right) {
			int mid = (left + right) >> 1;
			if (srt[mid] < t) left = mid + 1;
			else right = mid;
		}
		return right;
	}

	void update_lazy(int node, int start, int end) {
		if (!lazy[node]) return;
		seg[node] += lazy[node] * (end - start + 1);
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	void update_range(int node, int start, int end, int left, int right) {
		update_lazy(node, start, end);
		if (right < start || end < left) return;
		if (left <= start && end <= right) {
			seg[node] += (end - start + 1);
			if (start != end) {
				lazy[node * 2] += 1;
				lazy[node * 2 + 1] += 1;
			}
			return;
		}
		int mid = (start + end) >> 1;
		update_range(node * 2, start, mid, left, right);
		update_range(node * 2 + 1, mid + 1, end, left, right);
		seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}

	void solve(int node, int start, int end) {
		if (lazy[node]) {
			seg[node] += lazy[node];
			if (start != end) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
		if (start == end) {
			ans = max(ans, seg[node]);
			return;
		}
		int mid = (start + end) >> 1;
		solve(node * 2, start, mid);
		solve(node * 2 + 1, mid + 1, end);
	}

};

int main_2() {
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	scanf("%d\n", &n);
	Segment X(n), Y(n);
	vector<int> xsrt, ysrt;
	for (int i = 0, x, y;i < n;++i) {
		scanf("%d %d", &x, &y);
		arr.push_back({ x,y });
		X.srt.push_back(x);
		Y.srt.push_back(y);
	}
	arr.push_back(arr[0]);
	sort(X.srt.begin(), X.srt.end());
	X.srt.erase(unique(X.srt.begin(), X.srt.end()), X.srt.end());
	sort(Y.srt.begin(), Y.srt.end());
	Y.srt.erase(unique(Y.srt.begin(), Y.srt.end()), Y.srt.end());
	int xsz = X.srt.size(), ysz = Y.srt.size();
	for (int i = 1;i <= n;++i) {
		if (arr[i - 1].first == arr[i].first) {
			int a = arr[i - 1].second, b = arr[i].second;
			if (a > b) swap(a, b);
			Y.update_range(1, 0, ysz - 1, Y.lower(0, ysz, a), Y.lower(0, ysz, b) - 1);
		}
		else {
			int a = arr[i - 1].first, b = arr[i].first;
			if (a > b) swap(a, b);
			X.update_range(1, 0, xsz - 1, X.lower(0, xsz, a), X.lower(0, xsz, b) - 1);
		}
	}
	X.solve(1, 0, xsz - 1);
	Y.solve(1, 0, ysz - 1);
	printf("%d", max(X.ans, Y.ans));
	return 0;
}