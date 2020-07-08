#include <iostream>
#define N 1000001
using namespace std;

int n, arr[N], L_gcd[N + 1], R_gcd[N + 1];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1;i <= n;++i) cin >> arr[i];
	for (int i = 1;i <= n;++i) {
		L_gcd[i] = gcd(arr[i], L_gcd[i - 1]);	// 왼쪽에서 출발
		R_gcd[n - i + 1] = gcd(arr[n - i + 1], R_gcd[n - i + 2]);	// 오른쪽에서 출발
	}
	int max_gcd = R_gcd[1], ans1 = 0, ans2;	// max_gcd에 가장 작은 최대 공약수를 넣어줌, L_gcd[n] 해줘도 됨
	for (int i = 1;i <= n;++i) {
		int k = gcd(L_gcd[i - 1], R_gcd[i + 1]);	// arr[i]를 뺏을 때 최대 공약수 k를 구함
		if (k > max_gcd) {
			max_gcd = ans1 = k;
			ans2 = arr[i];
		}
	}
	if (!ans1) cout << "-1";
	else cout << ans1 << ' ' << ans2;
	return 0;
}