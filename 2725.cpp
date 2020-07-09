#include <iostream>
#define MAX_N 1001
using namespace std;

int dp[MAX_N], phi[MAX_N], t, n;

void solve_1() {

	// 오일러 피 함수 ( 난 잘 모르겠다..... )
	for (int i = 1;i < MAX_N;++i) phi[i] = i;
	for (int i = 2;i < MAX_N;++i) {
		if (phi[i] == i) {
			for (int j = i;j < MAX_N;j += i) phi[j] = phi[j] - phi[j] / i; // ( 1 - 1/p )
		}
	}
	dp[1] = 3;
	for (int i = 2;i < MAX_N;++i) dp[i] = dp[i - 1] + phi[i] * 2;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}

}

// 미리 0과 3으로 초기화
int dp[MAX_N] = { 0,3, }, t, n;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void solve_2() {

	for (int i = 2;i < MAX_N;++i) {
		int cnt = 0;
		for (int j = 0;j < i;++j) if (gcd(i, j) == 1) cnt += 2;	// i와 j가 서로소 ==> 유일한 기울기를 가짐
		dp[i] = dp[i - 1] + cnt;
	}
	
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}

}