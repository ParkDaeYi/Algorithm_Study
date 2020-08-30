#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>
#define N 3001
#define SZ 4096
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;

struct Point {
	int x, y, w;
	bool operator<(const Point& p) const {
		return x < p.x;
	}
}arr[N];
struct Node {
	ll sum, l, r, lr;
	// sum:	그 구간에 속한 모든 원소의 합
	// l:	왼쪽 끝에서부터 연속한 원소의 최대 합
	// r:	오른쪽 끝에서부터 연속한 원소의 최대 합
	// lr:	그 구간에서 나올 수 있는 최대 연속합
}seg[SZ * 2];
int n;
vector<int> ypos, xpos;

Node f(Node& a, Node& b) {
	Node ret;
	ret.sum = a.sum + b.sum;
	ret.l = max(a.l, a.sum + b.l);
	ret.r = max(b.r, a.r + b.sum);
	ret.lr = max({ a.r + b.l,a.lr,b.lr,ret.sum });
	return ret;
}

void su(int i, ll v) {
	i |= SZ;
	seg[i].sum = seg[i].l = seg[i].r = seg[i].lr += v;
	while (i >>= 1) {
		seg[i] = f(seg[i << 1], seg[i << 1 | 1]);
	}
}

int main() {
	scanf("%d\n", &n);
	for (int i = 0, x, y, w;i < n;++i) {
		scanf("%d %d %d", &x, &y, &w);
		arr[i] = { x,y,w };
		xpos.emplace_back(x);
		ypos.emplace_back(y);
	}
	sort(xpos.begin(), xpos.end());
	sort(ypos.begin(), ypos.end());
	xpos.erase(unique(xpos.begin(), xpos.end()), xpos.end());
	ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());
	for (int i = 0;i < n;++i) {
		arr[i].x = lower_bound(xpos.begin(), xpos.end(), arr[i].x) - xpos.begin();
		arr[i].y = lower_bound(ypos.begin(), ypos.end(), arr[i].y) - ypos.begin();
	}
	sort(arr, arr + n);
	ll ans = 0;
	for (int i = 0;i < n;++i) {
		// X 좌표가 같은 점들은 반드시 동시에 처리되어야 함
		if (i && arr[i].x == arr[i - 1].x) continue;
		memset(seg, 0, sizeof(seg));
		for (int j = i;j < n;++j) {
			su(arr[j].y, arr[j].w);
			// X 좌표가 같은 점들은 반드시 동시에 처리되어야 함
			// arr[i].x 에서 arr[n-1].x 사이에서 발생하는 max 값 중
			// 최대 값을 찾음
			if (j == n - 1 || arr[j].x ^ arr[j + 1].x) ans = max(ans, seg[1].lr);
		}
	}
	printf("%lld", ans);
	return 0;
}