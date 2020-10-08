#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int N, arr[100001];
ll mn = 0x7fffffff;
pll ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0;i < N;++i) cin >> arr[i];
	//sort(arr, arr + N);
	int l = 0, r = N - 1;
	while (l < r) {
		ll sum = arr[l] + arr[r];
		if (labs(mn) > labs(sum)) {
			mn = sum;
			ans = pll(arr[l], arr[r]);
		}
		if (sum < 0) ++l;
		else --r;
	}
	cout << ans.first << ' ' << ans.second;
	return 0;
}