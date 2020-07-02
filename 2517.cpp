#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, seg[1 << 21];
pii arr[500000];

int query(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return seg[node];
 	if (right < start || end < left) return 0;
	int mid = (start + end) >> 1;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first;	// 실력
		arr[i].second = i;	// 등수
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i) arr[i].first = i;	// 실력은 최대 1e9까지 값을 가질 수 있다. 근데 그만큼 배열을 선언할 수 없으므로
	// 실력 값을 재설정 해준다 (n은 최대 5e5이므로 충분히 배열을 사용할 수 있다)
	sort(arr, arr + n, [](const pii& p1, const pii& p2) {	// 다시 등수별로 정렬을 해준다
		return p1.second < p2.second;
	});
	const int sz = pow(2, (int)log2(n - 1) + 1);	// 세그먼트 트리 사이즈 설정
	for (int i = 0; i < n; ++i) {
		cout << query(1, 0, sz - 1, arr[i].first, n - 1) + 1 << '\n';	// 현재 실력보다 뛰어난 실력을 가진 선수들이 앞에 몇명 있는지가 최선의 등수가 된다.
		for (int node = arr[i].first + sz; node > 0; node /= 2) seg[node]++;	// 세그먼트 트리 업데이트
	}
	return 0;
}