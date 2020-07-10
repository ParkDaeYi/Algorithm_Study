#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> prime, res;
int arr[101], n, cnt, ans = 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0, tmp; i < n; ++i) {
		cin >> arr[i];
		tmp = arr[i];
		// 에라토스테네스의 체, 소수 판별 및 사용할 개수 체크
		while (tmp % 2 == 0) {
			tmp /= 2;
			prime[2]++;
		}
		for (int j = 3; j * j <= arr[i]; j += 2) {
			while (tmp % j == 0) {
				tmp /= j;
				prime[j]++;
			}
		}
		if (tmp > 1) prime[tmp]++;
	}
	
	for (auto p : prime) if (p.second >= n) res[p.first] = p.second / n;	// 사용된 소수 중 사용할 수 있는 소수의 개수를 저장
	// ex. 8 24 9
	// 8 : 2 2 2
	// 24: 2 2 2 3
	// 9 : 3 3
	// 2의 개수는 6개, 3의 개수는 3개
	// 상근이가 가장 큰 점수를 얻을려면 2를 2개, 3을 1개 사용하면 됨
	// ==> 2 * 2 * 3 = 12

	for (int i = 0, tmp; i < n; ++i) {
		tmp = arr[i];
		for (auto r : res) {
			int num = 0;
			while (tmp % r.first == 0) {
				tmp /= r.first;
				num++;
			}
			if (r.second > num) cnt += r.second - num;	// 최소 반복 횟수
			// ex. 8 24 9
			// 8의 경우 3을 하나 추가
			// 24의 경우는 X
			// 9의 경우는 2를 두개 추가
		}
	}
	for (auto r : res) for (int i = 0; i < r.second; ++i) ans *= r.first;
	cout << ans << ' ' << cnt;
	return 0;
}