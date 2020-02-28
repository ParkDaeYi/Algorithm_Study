#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX_Y 30000
using namespace std;

class info {
public:
	int x, y1, y2, val;
	info(int x = 0, int y1 = 0, int y2 = 0, int val = 0) :x(x), y1(y1), y2(y2), val(val) {}
};

int seg[1 << 21], cnt[1 << 21], n, ans;
info arr[20000];

void update_tree(int, int, int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0, a, b, c, d; i < n; ++i) {
		cin >> a >> b >> c >> d;
		//왼쪽 세로변과 오른쪽 세로변을 받음
		//1은 시작, -1은 끝을 가르킴
		arr[i] = info(a, b, d - 1, 1);
		arr[i + n] = info(c, b, d - 1, -1);
	}
	//x좌표로 정렬
	sort(arr, arr + n + n, [](const info& a, const info& b) {
		return a.x < b.x;
	});
	const int sz = pow(2, log2(MAX_Y - 1) + 1); //이미 size가 정해져있으므로 굳이 안구해도 되긴함
	for (int i = 0, prev; i < n + n; ++i) {
		//현재 x와 이전 x좌표 차이에 y를 곱함
		if (i) ans += (arr[i].x - prev) * seg[1];
		update_tree(1, 0, sz - 1, arr[i].y1, arr[i].y2, arr[i].val);
		prev = arr[i].x;
	}
	cout << ans;
	return 0;
}

void update_tree(int node, int start, int end, int left, int right, int val) {
	if (end < left || right < start) return;
	if (left <= start && end <= right) cnt[node] += val; //현재 y의 길이를 알기 위해 필요함
	else {
		int mid = (start + end) >> 1;
		update_tree(node * 2, start, mid, left, right, val);
		update_tree(node * 2 + 1, mid + 1, end, left, right, val);
	}
	if (cnt[node]) seg[node] = end - start + 1; //현재 구간에 해당하는 y(높이)를 저장
	else {
		//만약 cnt[node]가 0이면 해당 직사각형의 높이를
		//세그먼트에 포함하면 안됨.
		if (start == end) seg[node] = 0;
		else seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
}