#include <iostream>
#define N 100001
using namespace std;

int n, m, arr[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1;i <= n;++i) cin >> arr[i], arr[i] += arr[i - 1];
	int a, b;
	while (m--) {
		cin >> a >> b;
		cout << arr[b] - arr[a - 1] << '\n';
	}
	return 0;
}