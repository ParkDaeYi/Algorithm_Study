#include <iostream>
using namespace std;

int n, arr[100001], idx, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	while (n--) {
		cin >> arr[idx];
		if (arr[idx]) ++idx;
		else --idx;
	}
	for (int i = 0;i < idx;++i) ans += arr[i];
	cout << ans;
	return 0;
}