#include <iostream>
using namespace std;

int n, s, arr[20], ans;

void dfs(int idx, int sum) {
	if (idx == n) return;   // 인덱스 범위가 벗어났을 경우
	sum += arr[idx];
	if (sum == s) ++ans;    // 찾고자하는 값과 같음
	dfs(idx + 1, sum);  // 현재 배열 선택
	dfs(idx + 1, sum - arr[idx]);   // 현재 배열 선택 안함
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> s;
	for (int i = 0;i < n;++i) cin >> arr[i];
	dfs(0, 0);
	cout << ans;
	return 0;
}