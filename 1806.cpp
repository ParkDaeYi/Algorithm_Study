#include <iostream>
#include <algorithm>
using namespace std;

int n, s, ans = 1e9, arr[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int low = 0, high = 0, sum = arr[0];
	while (low <= high && high < n) {
		if (sum < s) sum += arr[++high];	// s보다 sum이 작으면 더해줌
		else {
			ans = min(ans, high - low);	// 현재 길이가 ans보다 작을 경우 ans 값 갱신
			sum -= arr[low++];	// sum 값을 빼줌
			if (low > high && low < n) {	// 예외 처리
				high = low;
				sum = arr[high];
			}
		}
	}
	if (ans == 1e9) cout << 0;	// 불가능
	else cout << ans + 1;
	return 0;
}