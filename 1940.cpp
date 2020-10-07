#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, arr[15001] = { 0, };
	cin >> N >> M;
	for (int i = 0;i < N;++i) cin >> arr[i];
	sort(arr, arr + N);
	int l = 0, r = N - 1, cnt = 0;
	while (l < r) {
		int sum = arr[l] + arr[r];
		if (sum == M) ++cnt, ++l, --r;
		else if (sum < M) ++l;
		else --r;
	}
	cout << cnt;
	return 0;
}