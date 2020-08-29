#include <stdio.h>
#include <vector>
#define N 100001
#pragma warning(disable:4996)
using namespace std;

int n, q;
vector<int> seg[N * 4];

void build(vector<int>& a,vector<int>& b,vector<int>& c) {
	int l = 0, r = 0, bsz = b.size(), csz = c.size();
	while (l < bsz && r < csz) {
		if (b[l] < c[r]) a.push_back(b[l++]);
		else a.push_back(c[r++]);
	}
	while (l < bsz) a.push_back(b[l++]);
	while (r < csz) a.push_back(c[r++]);
}

int upper(vector<int>& v, int l, int r, int k) {
	while (l < r) {
		int m = (l + r) >> 1;
		if (v[m] <= k) l = m + 1;
		else r = m;
	}
	return r;
}

int query(int l, int r, int k) {
	int ret = 0;
	for (l += n, r += n;l <= r;l >>= 1, r >>= 1) {
		if (l % 2) {
			ret += upper(seg[l], 0, seg[l].size(), k);
			l++;
		}
		if (r % 2 == 0) {
			ret += upper(seg[r], 0, seg[r].size(), k);
			r--;
		}
	}
	return ret;
}

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	scanf("%d %d\n", &n, &q);
	for (int i = 0, x;i < n;++i) {
		scanf("%d", &x);
		seg[i + n].push_back(x);
	}
	for (int i = n - 1;i > 0;--i) build(seg[i], seg[i << 1], seg[i << 1 | 1]);
	int i, j, k;
	while (q--) {
		scanf("%d %d %d", &i, &j, &k);
		int l = seg[1][0], r = seg[1].back();
		--i, --j;
		/*
		머지 소트 정렬을 하더라도 리프 노드에 있는
		값이 주어진 범위 안에서 몇 번째 수인지 알 수 없음
		그러므로 이분탐색을 통해 수를 추출하고
		upper_bound를 통해 해당 수가 몇 번째 수인지
		가늠한다.
		*/
		while (l <= r) {
			int m = (l + r) >> 1;
			if (query(i, j, m) < k) l = m + 1;
			else r = m - 1;
		}
		printf("%d\n", l);
	}
	return 0;
}

// 1차원 배열을 사용한 풀이
#include <algorithm>
#define N 100001

struct Array {
	int val, idx;
}arr[N];
int n, q;

int solve_2() {
	scanf("%d %d\n", &n, &q);
	for (int i = 0;i < n;++i) {
		scanf("%d", &arr[i].val);
		arr[i].idx = i + 1;
	}
	std::sort(arr, arr + n, [&](Array a, Array b) {
		return a.val < b.val;
		});
	// ex.
	//	value	1	5	2	6	3	7	4
	//	index	1	2	3	4	5	6	7
	// 을 정렬
	//	value	1	2	3	4	5	6	7
	//	index	1	3	5	7	2	4	6
	// 에서 범위 i, j에 속하면 cnt++
	// 만약 cnt 값이 k 값과 같아지면 출력하면 된다
	int a, b, c;
	while (q--) {
		scanf("%d %d %d", &a, &b, &c);
		for (int i = 0, cnt = 0;i < n;++i) {
			if (a <= arr[i].idx && arr[i].idx <= b) cnt++;
			if (cnt == c) {
				printf("%d\n", arr[i].val);
				break;
			}
		}
	}
	return 0;
}