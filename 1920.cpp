#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[100000];

bool solve(int target) {
	// 전형적인 이분탐색
	int mid, left = 0, right = n;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (arr[mid] == target) return 1;	// 찾았을 경우 return
		else if (arr[mid] < target) left = mid + 1;	// target이 arr[mid]보다 클 경우 더 오른쪽으로 이동을 해야하므로 left를 mid+1로 이동
		else right = mid - 1;	// target이 arr[mid]보다 작을 경우 더 왼쪽으로 이동해야 함
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);	// 이분탐색을 수월하게 하기 위해 정렬을 해줌
	cin >> m;
	for (int i = 0, x; i < m; ++i) {
		cin >> x;
		cout << solve(x) << '\n';
	}

	return 0;
}