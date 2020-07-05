#include <iostream>
#include <algorithm>
using namespace std;

int n, h, bot[100000], top[100000], ans = 1e9, cnt, i, j;

int lower_bd(int arr[], int left, int right, int target) {
	while (left < right) {
		int mid = (left + right) >> 1;
		if (arr[mid] < target) left = mid + 1;
		else right = mid;
	}
	return right;
}

void solve_1() {

	cin >> n >> h;
	for (; i + j < n;) cin >> ((i + j) % 2 ? top[j++] : bot[i++]);	// 짝수 : bot(석순), 홀수 : top(종유석)
	// Lower Bound를 위해 정렬
	sort(bot, bot + i);
	sort(top, top + j);
	for (int high = 1; high < h + 1; ++high) {
		int b = i - lower_bd(bot, 0, i, high);	// i - (0 ~ i 중  0 ~ high 석순의 개수)
		int t = j - lower_bd(top, 0, j, h - high + 1);	// j - (0 ~ j 중 0 ~ h-high+1 종유석의 개수)
		if (b + t < ans) {
			ans = b + t;
			cnt = 1;
		}
		else if (ans == b + t) ++cnt;
	}
	cout << ans << ' ' << cnt;
}

#include <cmath>

int n, h, bot[1 << 21], top[1 << 21], ans = 1e9, cnt;

int query(int arr[], int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return arr[node];
	if (end < left || right < start) return 0;
	int mid = (start + end) >> 1;
	return query(arr, node * 2, start, mid, left, right) + query(arr, node * 2 + 1, mid + 1, end, left, right);
}

void solve_2() {
	// 세그먼트 트리
	cin >> n >> h;
	const int sz = pow(2, (int)log2(h - 1) + 1);
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		i % 2 ? top[sz + x - 1]++ : bot[sz + x - 1]++;
	}
	for (int i = sz - 1; i > 0; --i) bot[i] = bot[i * 2] + bot[i * 2 + 1], top[i] = top[i * 2] + top[i * 2 + 1];
	for (int i = 1; i < h + 1; ++i) {
		int tmp = query(bot, 1, 1, sz, i, h) + query(top, 1, 1, sz, h - i + 1, h);
		if (tmp < ans) {
			ans = tmp;
			cnt = 1;
		}
		else if (ans == tmp) cnt++;
	}
	cout << ans << ' ' << cnt;
}

int n, h, bot[500001], top[500001], ans = 1e9, cnt;

void solve_3() {
	// 구간 합
	cin >> n >> h;
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		i % 2 ? top[x]++ : bot[x]++;
	}
	for (int i = 1; i < h + 1; ++i) bot[i] += bot[i - 1], top[i] += top[i - 1];	// 구간별 합을 저장
	for (int i = 0, x; i < h; ++i) {
		x = bot[h] - bot[i] + top[h] - top[h - i - 1];
		if (x < ans) {
			ans = x;
			cnt = 1;
		}
		else if (x == ans) ++cnt;
	}
	cout << ans << ' ' << cnt;
}