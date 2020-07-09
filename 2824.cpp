#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
typedef long long int llt;

int N, M;
vector<int> vn, vm;
llt ans = 1;

void init(int n, vector<int>& v) {
	// 각 값마다 소인수 분해 해줌
	for (int i = 0, x;i < n;++i) {
		cin >> x;
		while (x % 2 == 0) {
			x /= 2;
			v.push_back(2);
		}
		for (int i = 3;i * i <= x;i += 2) {
			while (x % i == 0) {
				x /= i;
				v.push_back(i);
			}
		}
		if (x > 1) v.push_back(x);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	init(N, vn);
	cin >> M;
	init(M, vm);
	// 투 포인터로 값을 찾을 것이므로 정렬
	sort(vn.begin(), vn.end());
	sort(vm.begin(), vm.end());

	auto p1 = vn.begin(), p2 = vm.begin();
	bool flag = 0;
	while (p1 != vn.end() && p2 != vm.end()) {
		if (*p1 == *p2) {
			ans *= *p1;
			++p1, ++p2;
			if (ans >= INF) {
				ans %= INF;
				flag = 1;	// 십억을 넘길 시 체크
			}
		}
		else if (*p1 < *p2) ++p1;
		else ++p2;
	}
	if (flag) {
		string str = to_string(ans);
		for (int i = 0;i < 9 - str.size();++i) cout << 0;
	}
	cout << ans;
	return 0;
}