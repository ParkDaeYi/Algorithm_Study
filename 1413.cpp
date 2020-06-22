#include <iostream>
using namespace std;
typedef long long llt;

llt gcd(llt a, llt b) {
	return b ? gcd(b, a % b) : a;
}

int n, m;
llt dp[21][21] = { 1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= i; j++) 
			dp[i][j] = dp[i - 1][j - 1] + (i - 1) * dp[i - 1][j]; //제 1종 스털링 수 점화식
	for (int i = 1; i <= n; i++) dp[n][i] += dp[n][i - 1]; // 모든 k 갯수의 사이클을 더함
	llt g = gcd(dp[n][m], dp[n][n]);
	cout << dp[n][m] / g << "/" << dp[n][n] / g;
	return 0;
}

// 제 1종 스털링 수 ( 1 ~ n 까지의 수가 있을 때, k 개의 사이클을 만들 수 있는 경우의 수 [n, k] )
// 1 ~ n 까지의 수가 있을 때, k 개의 사이클을 만들 수 있는 경우의 수 [n, k]
// [1, 1] = 1, [n, 0] = 0, [n, 1] = (n - 1)!, [n, n] = 1,
// [n, k] = [n - 1, k - 1] + (n - 1) * [n - 1, k]
// [n - 1, k - 1] : 새로운 사이클에 끼어드는 경우, [n - 1, k] : 기존 사이클에 끼어드는 경우

// 제 2종 스털링 수 ( n 개의 수를 k 개의 파티션으로 나누는 방법 {n, k} )
// {1, 1} = 1, {n, 0} = 0, {n, 1} = 1, {n, n} = 1,
// {n, k} = {n - 1, k - 1} + k * {n - 1, k}
// {n - 1, k - 1} : n 번째 원소를 싱글그룹으로 만든다, k * {n - 1, k} : n - 1 개의 k 개의 그룹 중 하나에 삽입

// Integer Partition ( 정수를 다른 정수들의 합으로 표현 ex. 5: [5], [4][1], [3][2], [3][1][1].....)
// 이 때, f(n, k)는 n을 덧셈으로 표현하되, 제일 큰 수는 k 이하인 파티션의 개수
// f(n, k), if(k > n) = f(n, n)
// f(n, 1) = 1, f(n, 0) = 0, f(1, 1) = 1,
// f(n, k) = f(n - k, k) + f(n, k - 1)
// f(n - k , k) : 제일 큰 수가 k 일 때, f(n, k - 1) : 제일 큰 수가 k가 아닐 때