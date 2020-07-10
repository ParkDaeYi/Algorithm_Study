#include <iostream>
using namespace std;
typedef long long int llt;

int n, t;
bool visit[21];
llt k, fac[20] = { 1,1, }, cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> t;
	for (int i = 2; i < n; ++i) fac[i] = fac[i - 1] * i;
	if (t == 1) {
		// 1의 경우 백트랙킹으로 구할 수 있지만
		// 2는 팩토리얼로 풀어야하므로 그냥 얘도 팩토리얼로 품
		cin >> k;
		for (int i = 0; i < n; ++i) 
			for (int j = 1; j <= n; ++j) {
				// ex. n = 4
				//	1 2 3 4		2 1 3 4		3 1 2 4		4 1 2 3
				//	1 2 4 3		2 1 4 3		3 1 4 2		4 1 3 2
				//	1 3 2 4		2 3 1 4		3 2 1 4		4 2 1 3
				//	1 3 4 2		2 3 4 1		3 2 4 1		4 2 3 1
				//	1 4 2 3		2 4 1 3		3 4 1 2		4 3 1 2
				//	1 4 3 2		2 4 3 1		3 4 2 1		4 3 2 1
				// 첫 번째 자리는 6가지 경우, 두 번째는 2 가지, 세 네번째는 1 가지~~~~~
				// 총 경우의 수는 24, 6, 2, 1
				// 즉, 각 자리수의 총 경우의 수는 fac[n - i], 정해진 숫자에서는 fac[n - i - 1]가지의 경우를 가진다
				if (visit[j]) continue;	// 사용한 숫자면 스킵
				if (k > fac[n - i - 1]) k -= fac[n - i - 1];
				else {
					cout << j << ' ';
					visit[j] = 1;
					break;
				}
			}
	}
	else {
		for (int i = 0, x; i < n; ++i) {
			cin >> x;
			for (int j = 1; j < x; ++j) {
				if (!visit[j]) cnt += fac[n - i - 1];	// x보다 작고 사용하지 않았다면 +
			}
			visit[x] = 1;	// 사용한 숫자 체크
		}
		cout << cnt + 1;
	}
	return 0;
}