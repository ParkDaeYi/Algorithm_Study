#include <iostream>
using namespace std;

int n, m, arr[10001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int low = 0, high = 0, sum = arr[0], cnt = 0;

	while (high < n) {	// high가 n이 될때까지 반복
		if (sum < m) sum += arr[++high];	// m 보다 작으면 '+'
		else if (sum == m) {	// m일 경우 '+'해도 되고 '-'해도 되고 맘대로
			sum += arr[++high];
			cnt++;
		}
		else sum -= arr[low++];	// m보다 클 경우 '-'
	}
	// 이 소스가 더 안정적이긴 하다 (m보다 클 경우 예외처리가 있음)
	//while (low <= high && high < n) {
	//	if (sum < m)
	//		sum += arr[++high];
	//	else if (sum == m) {
	//		cnt++;
	//		sum += arr[++high];
	//	}
	//	else {
	//		sum -= arr[low++];
	//		if (low > high && low < n) {	// 만약 low가 high보다 커질 경우 조정을 해줘야 함
	//			high = low;
	//			sum = arr[low];
	//		}
	//	}
	//}
	cout << cnt;

	return 0;
}