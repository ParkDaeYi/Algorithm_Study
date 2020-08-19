#include <iostream>
#define N 2001
using namespace std;

int n, m, arr[N];
bool dp[N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1;i <= n;++i) cin >> arr[i];
	// 길이가 1~2인 팰린드롬을 구함
	for (int i = 1;i <= n;++i) {
		dp[i][i] = 1;
		if (arr[i - 1] == arr[i]) dp[i - 1][i] = 1;
	}
	// 길이가 3이상인 팰린드롬을 구함
	// ==> 앞 뒤를 비교하고 그 사이 값은 미리 구해둔 팰린드롬 값으로 판단
	for (int i = 2;i < n;++i) 
		for (int j = 1;j <= n - i;++j) {
			int k = i + j;
			if (arr[j] == arr[k] && dp[j + 1][k - 1]) dp[j][k] = 1;
		}
	
	cin >> m;
	for (int i = 0, a, b;i < m;++i) {
		cin >> a >> b;
		cout << dp[a][b] << '\n';
	}
	return 0;
}