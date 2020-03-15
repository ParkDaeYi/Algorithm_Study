#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, se, ans, arr[300010];
double sum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	if (!n) {
		cout << 0;
		return 0;
	}
	se = (int)floor(n * 0.15f + 0.5f);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = se; i < n - se; ++i) sum += arr[i];	
	ans = (int)floor(sum / (n - se * 2) + 0.5f);
	cout << ans;
	return 0;
}