#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int llt;

int T, n, m, A_arr[1000], B_arr[1000];
vector<int> A, B;
llt ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T >> n;
	for (int i = 0; i < n; ++i) cin >> A_arr[i];
	for (int i = 0; i < n; ++i) {	// 계산 과정을 줄이기 위해 미리 부 배열의 합들을 구해 둠
		int sum = A_arr[i];
		A.push_back(sum);
		for (int j = i + 1; j < n; ++j) {
			sum += A_arr[j];
			A.push_back(sum);
		}
	}
	cin >> m;
	for (int i = 0; i < m; ++i) cin >> B_arr[i];
	for (int i = 0; i < m; ++i) {
		int sum = B_arr[i];
		B.push_back(sum);
		for (int j = i + 1; j < m; ++j) {
			sum += B_arr[j];
			B.push_back(sum);
		}
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int A_point = 0, B_point = B.size() - 1, tmp;	// A와 B의 시작 지점을 서로 다르게 지정(처음과 끝)
	while (A_point < A.size() && B_point >= 0) {
		llt sum = A[A_point] + B[B_point];
		if (sum < T) {
			tmp = A[A_point];
			while (A_point < A.size() && A[A_point] == tmp) A_point++;	// 같은 숫자의 경우 스킵
		}
		else if (sum > T) {
			tmp = B[B_point];
			while (B_point >= 0 && B[B_point] == tmp) B_point--;
		}
		else {
			llt A_cnt = 0, B_cnt = 0;
			tmp = A[A_point];
			while (A_point < A.size() && A[A_point] == tmp) A_point++, A_cnt++;	// 동일한 숫자의 갯수를 카운트
			tmp = B[B_point];
			while (B_point >= 0 && B[B_point] == tmp) B_point--, B_cnt++;
			ans += A_cnt * B_cnt;
		}
	}
	cout << ans;
	return 0;
}