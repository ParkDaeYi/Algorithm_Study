#include <iostream>
using namespace std;

int n, k, cnt;
bool prime[1001] = { 0,1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 2; i < n + 1; ++i) {
		if (!prime[i]) {
			for (int j = i; j < n + 1; j += i) {
				if (!prime[j]) {
					prime[j] = 1;	// 갯수 카운트를 위해서 그냥 i부터 체크
					cnt++;
					if (cnt == k) {
						cout << j;
						return 0;
					}
				}
			}
		}
	}
}