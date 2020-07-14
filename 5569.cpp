#include <iostream>
#define MOD 100000
using namespace std;

int dp[101][101][2][2], W, H;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> W >> H;
	
	// 첫 번째 인자 값, 0: 동쪽, 1: 북쪽
	// 두 번째 인자 값, 0: 한 칸, 1: 두 칸 이상
	
	// 동쪽 혹은 북쪽으로 이동 전 다른 방향에 끝에 1 추가
	// => 동쪽으로 이동하려면 북쪽으로 이동한 상태여야 하고
	//	북쪽으로 이동하려면 동쪽으로 이동한 상태여야하기 떄문
	for (int i = 0;i < W;++i) dp[i][0][0][0] = 1;
	for (int i = 0;i < H;++i) dp[0][i][1][0] = 1;

	for (int i = 1;i < W;++i) {
		for (int j = 1;j < H;++j) {
			// 한 칸 이동하는 경우는 다른 방향에서 두 칸 이상 이동해야 가능
			// 그러므로 한 칸 이동 후 바로 방향을 전환하는 경우와
			// 두 칸 이상 이동 후 방향 전환하는 경우를 구분하여 계산

			// 두 칸 이상 이동하는 경우(바로 방향 전환)는 다른 방향의 한 칸 이동 값을 가져옴
			// 한 칸 이동하는 경우(두 칸 이상 이동 후)는 바로 전 자신의 두 개 인자 값으로 갱신함
			dp[i][j][0][0] = (dp[i - 1][j][0][1] + dp[i - 1][j][0][0]) % MOD;
			dp[i][j][0][1] = dp[i - 1][j][1][0];
			dp[i][j][1][0] = (dp[i][j - 1][1][0] + dp[i][j - 1][1][1]) % MOD;
			dp[i][j][1][1] = dp[i][j - 1][0][0];
		}
	}
	// 모든 경우의 수를 더한 뒤 출력
	cout << (dp[W - 1][H - 1][0][0] + dp[W - 1][H - 1][0][1] + dp[W - 1][H - 1][1][0] + dp[W - 1][H - 1][1][1]) % MOD;
	return 0;
}