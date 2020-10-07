#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	vector<int> A, B, C;
	cin >> N >> M;
	for (int i = 0, x;i < N;++i) {
		cin >> x;
		A.emplace_back(x);
	}
	for (int i = 0, x;i < M;++i) {
		cin >> x;
		B.emplace_back(x);
	}
	int a = 0, b = 0;
	while (a < N && b < M) {
		if (A[a] < B[b]) C.emplace_back(A[a++]);
		else C.emplace_back(B[b++]);
	}
	while (a < N) C.emplace_back(A[a++]);
	while (b < M) C.emplace_back(B[b++]);
	for (int i : C) cout << i << ' ';
	return 0;
}