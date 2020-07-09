#include <iostream>
#include <string>
#define MAX 1000000
using namespace std;

string P;
int K;
bool prime[MAX + 1];

bool isBad(int m) {
	int ret = 0;
	for (int i = 0;i < P.size();++i) ret = (ret * 10 + P[i] - '0') % m;	// m으로 나눠지는지 계산
	return ret ? 0 : 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> P >> K;
	for (int i = 2;i < K;++i) {
		if (prime[i]) continue;
		if (isBad(i)) {
			cout << "BAD " << i;
			return 0;
		}
		if (1LL * i * i >= K) continue;
		for (int j = i * i;j < K;j += i) prime[j] = 1;
	}
	cout << "GOOD";
	return 0;
}