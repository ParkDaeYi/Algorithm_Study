#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int llt;

int n, m, tree[1000000], h;
llt ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> tree[i], h = max(h, tree[i]);

	int left = 0, right = h;	// 주어진 나무 중 가장 큰 나무를 right로 지정, 연산 수를 줄이기 위함
	while (left <= right) {
		int mid = (left + right) >> 1;
		llt sum = 0;
		for (int i = 0; i < n; ++i) sum += (tree[i] - mid) > 0 ? (tree[i] - mid) : 0;
		if (sum < m) right = mid - 1;	// sum이 m보다 같거나 크게 만들어야함 ==> right를 줄이면 mid 값이 줄면서 sum 값이 커짐
		else {
			ans = mid;
			left = mid + 1;	// 높이의 최대 값을 알아야 하므로 sum값이 m가 가장 가깝운 값이 되어야 함 
		}
	}
	cout << ans;
	return 0;
}