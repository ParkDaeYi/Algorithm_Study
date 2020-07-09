#include <iostream>
#include <vector>
#define MAX_N 4000000
using namespace std;

int n;
bool prime[MAX_N + 1];
vector<int> primes;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	// 에라토스테네스의 체(가속(?)), 소수 추출
	primes.push_back(2);
	for (int i = 4;i < MAX_N + 1;i += 2) prime[i] = 1;	// 2의 배수 미리 걸러줌
	for (int i = 3;i < MAX_N + 1;i += 2) {
		if (prime[i]) continue;
		primes.push_back(i);
		if (1LL * i * i >= n) continue;
		for (int j = i * i;j < MAX_N + 1;j += i * 2) prime[j] = 1;
	}
	// 투 포인터를 사용해서 개수를 구함
	int low = 0, high = 0, sum = 0, cnt = 0;
	while (low <= high && high < primes.size()) {
		if (sum < n) sum += primes[high++];
		else if (sum == n) {
			cnt++;
			sum += primes[high++];
		}
		else {
			sum -= primes[low++];
			if (low > high && low < primes.size()) {
				high = low;
				sum = primes[high];
			}
		}
	}
	cout << cnt;
	return 0;
}