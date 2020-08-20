#include <iostream>
using namespace std;

int n, rby[3][2];
double len;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> len;
	for (int i = 0;i < 3;++i) cin >> rby[i][0] >> rby[i][1];
	for (int i = 0;i < 3;++i) {
		if (rby[i][0] == rby[i][1]) continue;
		double tmp, mid;
		mid = (rby[i][0] + rby[i][1]) / 2.0;
		// 중점을 기준으로 오른쪽이 왼쪽보다 길 경우
		// 왼쪽을 오른쪽으로 접음
		if (mid < len - mid) {
			for (int j = i + 1;j < 3;++j) {
				for (int k = 0;k < 2;++k) {
					// 우측을 기준으로 숫자를 맞춤
					// ex.
					// 1 2 3 4 5 6 7 8 9 10 에서
					// 10 9 8 7 6 5 4 3 2 1 로
					if (rby[j][k] < mid) rby[j][k] += len - (mid * 2);
					else rby[j][k] = len - rby[j][k];
				}
			}
			len -= mid;
		}
		// 중점을 기준으로 왼쪽이 오른쪽보다 길 경우
		else {
			// 왼쪽은 그대로 둠
			for (int j = i + 1;j < 3;++j) 
				for (int k = 0;k < 2;++k) if (rby[j][k] > mid) rby[j][k] = mid * 2 - rby[j][k];
			len = mid;
		}
	}
	cout.precision(1);
	cout << fixed << len;
	return 0;
}