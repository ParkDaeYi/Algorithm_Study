#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[3], x[2][3], y[2][3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[0] >> arr[1] >> arr[2];

		x[1][0] = min(x[0][0], x[0][1]) + arr[0];	// 0에서는 0과 1로
		x[1][1] = min(x[0][0], min(x[0][1], x[0][2])) + arr[1];	// 1에서는 0, 1, 2
		x[1][2] = min(x[0][1], x[0][2]) + arr[2];	// 2에서는 1과 2로 이동 가능

		x[0][0] = x[1][0]; x[0][1] = x[1][1]; x[0][2] = x[1][2];	// 결과 값 저장

		y[1][0] = max(y[0][0], y[0][1]) + arr[0];
		y[1][1] = max(y[0][0], max(y[0][1], y[0][2])) + arr[1];
		y[1][2] = max(y[0][1], y[0][2]) + arr[2];

		y[0][0] = y[1][0]; y[0][1] = y[1][1]; y[0][2] = y[1][2];
	}

	cout << max(y[0][0], max(y[0][1], y[0][2])) << ' ' << min(x[0][0], min(x[0][1], x[0][2]));

	return 0;
}