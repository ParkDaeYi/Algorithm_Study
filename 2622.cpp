#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, ans = 0;
	cin >> n;
	// 삼각형 만드는 조건
	// 0 <= a <= b <= c && a + b + c = n && a + b > c
	// 이 세가지 조건을 통해 c와 b의 범위를 구할 수 있음
	for (int c = 1;c < n;++c) {
		// c 의 범위										b 의 범위
		// a <= c, b <= c									a <= b <= c
		//	-> a + b <= 2 * c								 -> a = n - b - c <= b <= c
		//	( a + b == 2 * c 가 되는 경우: 정삼각형)		 -> (n - c) / 2 <= b <= c
		//	-> a + b + c <= 3 * c								(n - c) / 2
		//	-> n <= 3 * c										==> a + b = n - c 를 2로 나눔
		// a + b > c												a를 가장 작은 변, c를 가장 큰 변으로 기준 잡았기 때문에
		//	-> n - c > c											(n - c) / 2 <= b 가 성립함
		//	-> n > 2 * c 
		// b 의 개수는 c - (n - c - 1) / 2 인데 - 1 을 해주는 이유는
		// (n - c) / 2 와 c 가 같을 수도(<=) 있기 때문
		if (n <= c * 3 && c * 2 < n)
			ans += c - (n - c - 1) / 2;
	}
	cout << ans;
	return 0;
}