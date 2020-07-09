#include <iostream>
#include <cmath>
#define MAX_N 100000
using namespace std;
typedef long long int llt;

// 카탈란 수의 핵심은 N 각형을 (N - 2) 개의 삼각형으로 나눌 수 있는 경우의 수 이다.
// N 값이 100000일 경우 N - 2까지만 알면 되므로 배열의 크기는 99999면 된다.
// 해당 문제에선 메모리 제한이 32MB이므로 최대한 딱 맞게 배열을 생성해준다.
int N, M, dp[MAX_N - 1] = { 1, };	// C0 = 1 이다.

int primes[(MAX_N - 1) * 2 + 1], prime_idx[(MAX_N - 1) * 2 + 1], factor[(MAX_N - 1) * 2 + 1];
// 카탈란 수는 Cn+1 = (2 * (2n + 1) / (n + 2)) * Cn 으로 나타낼 수 있다.
// 여기서 우리는 (2 * (2n + 1) / (n + 2)) 값을 구할건데 n + 2 는 소수가 아닐 수도 있기 때문에 모듈러 역원은 사용하지 못한다.
// 그러므로 소인수 분해를 사용하여 세그먼트 트리를 갱신해서 값을 도출할 것이다.
// 소인수 분해를 사용하기 때문에 2n + 1 까지의 소수는 구해둬야 한다.

int seg[(MAX_N - 1) * 2 + 1], leaf[MAX_N - 1], idx, sz;
// 곱셈 세그먼트 트리를 사용해서 카탈란 수를 구할 것이다.
// seg[1] 의 값은 Cn 의 값과 같다.
// leaf 노드를 통해 세그먼트 트리를 증가시키거나 감소시킬 것이다.
// ==> 2, 2n + 1 은 증가, n + 2 는 감소

// 에라토스테네스의 체
void sieve() {
	int len = (N - 1) * 2;
	for (int i = 2;i < len + 1;++i) prime_idx[i] = 1, primes[i] = i;
	for (int i = 2;i * i < len + 1;++i) {
		if (prime_idx[i]) {
			for (int j = i * i;j < len + 1;j += i) prime_idx[j] = 0, primes[j] = i;
		}
	}
	for (int i = 2;i < len + 1;++i) {
		if (prime_idx[i]) {
			prime_idx[i] = ++idx;	// factor에 저장된 소수의 위치를 저장
			factor[idx] = i;	// 현재 범위에 포함되는 소수를 저장
		}
	}
}

void init() {
	sz = pow(2, (int)log2(idx - 1) + 1);
	for (int i = 1;i < sz * 2;++i) seg[i] = 1;
}

// (x^n)%M 을 빠르게 구하기 위함
int expmod(int x, int n) {
	if (!n) return 1;
	int d = expmod(x, n / 2);
	llt dd = ((llt)d * d) % (llt)M;
	if (n % 2) return (int)((dd * x) % (llt)M);
	return (int)dd;
}

void insert(int idx, int diff) {
	int node = sz + idx - 1;
	leaf[idx - 1] += diff;	// 해당 소수 값 갱신
	seg[node] = expmod(factor[idx], leaf[idx - 1]);	// 현재 소수를 저장된 개수만큼 곱하고 MOD한 수로 갱신
	for (node /= 2;node > 0;node /= 2) seg[node] = (int)(((llt)seg[node * 2] * seg[node * 2 + 1]) % (llt)M);
	// 카탈란 수는 급격하게 상승하므로 long long int로 캐스팅을 해줘야 함
}

void query(int x, int diff) {
	while (x > 1) {
		int v = primes[x];	// x의 소인수
		insert(prime_idx[v], diff);	// x의 소인수가 저장된 위치, 변경할 값
		x /= v;	// x가 1이 될때까지 나눠준다.
	}
}

llt solve() {
	llt ret = 0;
	for (int i = 1;i < N - 1;++i) {
		int n = i - 1;
		query(2, 1);
		query(2 * n + 1, 1);
		query(n + 2, -1);
		// dp[i] == Cn+1
		// seg[1] == Cn
		// 위 3개 query가 (2 * (2n + 1) / (n + 2))
		// 즉 Cn+1 = (2 * (2n + 1) / (n + 2)) * Cn 식과 동일
		dp[i] = seg[1];
		ret = (ret + dp[i]) % (llt)M;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	sieve();	// 소수 구하기
	init();		// 세그먼트 트리 1로 초기화 (C0 = 1 이므로)
	cout << solve();
	return 0;
}