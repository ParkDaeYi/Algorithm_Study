#include <iostream>
using namespace std;
typedef long double ld;

int n, k, arr[50], sum;
ld ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i], sum += arr[i];	// 전체 조약돌 개수
	cin >> k;
	for (int i = 0; i < n; ++i) {
		if (arr[i] < k) continue;	// 조약돌 개수보다 뽑는 개수가 클 경우 스킵
		ld tmp = 1.0f;
		for (int j = 0; j < k; ++j) {
			tmp *= (ld)(arr[i] - j) / (ld)(sum - j);
			// ex. 5 6 7
			// sum = 18
			// 5 / 18, 4 / 17 ... (5 - k + 1) / (18 - k + 1)
			// 단순 확률 계산
		}
		ans += tmp;
	}
	cout.precision(10);
	cout << fixed << ans;
	return 0;
}