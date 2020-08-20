#include <iostream>
#include <algorithm>
using namespace std;

int n, k, arr[100001];

void ans(int sum, int d) {
	sum = sum / d;
	if (sum % 10 >= 5) sum += 10;
	sum /= 10;
	cout << sum / 100 << '.' << sum / 10 % 10 << sum % 10 << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	double d;
	for (int i = 0;i < n;++i) {
		cin >> d;
		// 소수점 2자리까지 출력하고 반올림을 해줘야 하므로 * 1000
		arr[i] = 1000 * d;
	}
	sort(arr, arr + n);
	int sum1 = 0, sum2 = 0;
	// 절사 평균을 구하고 보정 평균을 구함
	for (int i = k;i < n - k;++i) sum1 += arr[i];
	sum2 = sum1 + k * (arr[k] + arr[n - k - 1]);
	ans(sum1, n - k * 2);
	ans(sum2, n);
	return 0;
}