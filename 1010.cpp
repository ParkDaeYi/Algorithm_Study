#include <iostream>
using namespace std;

int t, n, m, dp[30][30];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	// 다리끼리는 서로 겹칠 수 없다.
	// 서쪽의 정점 N개는 모두 선택되어야 하고, 동쪽의 정점 M개 중 어떤 N개의 정점을 선택했을 때
	// 다리를 지을 수 있는 방법의 수는 항상 1이다
	// ex. 2 3
	//	1	1		1	1		1	0
	//	1	1		1	0		1	1
	//		0			1			1
	// 즉, M개 중 N개를 고르는 경우의 수를 구하는 문제이다. ==> 조합
	cin >> t;
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i < 30; ++i) {
		dp[i][0] = 1;
		for (int j = 0; j <= i; ++j) {
			if (i == j) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
	while (t--) {
		cin >> n >> m;
		cout << dp[m][n] << '\n';
	}
	return 0;
}