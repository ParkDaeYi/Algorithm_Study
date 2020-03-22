#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int llt;

int n;
llt arr[100001], sum[100001];

llt solve(int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	cout << solve(1, n);
	return 0;
}

llt solve(int start, int end) {
	if (start == end) return arr[start] * arr[start];
	int mid = (start + end) / 2;
	llt ret = max(solve(start, mid), solve(mid + 1, end));
	int left = mid, right = mid + 1;
	llt h = min(arr[left], arr[right]);
	ret = max(ret, (arr[left] + arr[right]) * h);
	while (start < left || right < end) {
		if (right < end && (start == left || arr[left - 1] < arr[right + 1])) h = min(h, arr[++right]);
		else h = min(h, arr[--left]);
		ret = max(ret, (sum[right] - sum[left - 1]) * h);
	}
	return ret;
}