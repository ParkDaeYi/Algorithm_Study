#include <iostream>
using namespace std;

int H, W, N, arr[1001][1001], dp[1002][1002];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> H >> W >> N;

	for (int i = 1; i <= H; ++i) for (int j = 1; j <= W; ++j) cin >> arr[i][j];

	// dp 배열엔 경우의 수를 저장
	// 홀수일 경우에는 한 번 더 이동하므로 + 1
	dp[1][1] = N;
	for (int i = 1; i <= H; ++i) {
		for (int j = 1; j <= W; ++j) {
			if (arr[i][j]) {
				dp[i][j + 1] += dp[i][j] % 2 ? dp[i][j] / 2 + 1 : dp[i][j] / 2;
				dp[i + 1][j] += dp[i][j] / 2;
			}
			else {
				dp[i][j + 1] += dp[i][j] / 2; 
				dp[i + 1][j] += dp[i][j] % 2 ? dp[i][j] / 2 + 1 : dp[i][j] / 2;
			}
		}
	}

	// dp 배열의 경우의 수가 
	// 짝수일 경우 반대 방향으로 이동했다는 뜻이고
	// 홀수일 경우에는 해당 방향으로 이동했다는 뜻임
	int i = 1, j = 1;
	for (; i <= H && j <= W;) {
		if (arr[i][j]) {
			if (dp[i][j] % 2) j++;
			else i++;
		}
		else {
			if (dp[i][j] % 2) i++;
			else j++;
		}
	}
	cout << i << ' ' << j;
	return 0;
}