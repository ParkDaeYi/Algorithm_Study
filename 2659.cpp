#include <iostream>
#include <algorithm>
using namespace std;

int arr[4];
bool used[10][10][10][10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0;i < 4;++i) cin >> arr[i];
	int tmp = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3], cnt = 0;
	int n = tmp;
	for (int i = 0;i < 3;++i) {
		tmp = tmp % 1000 * 10 + tmp / 1000;
		if (n > tmp) n = tmp;
	}

	for (int i = 1111;i <= n;++i) {
		int a = i / 1000, b = i / 100 % 10, c = i / 10 % 10, d = i % 10;
		if (!a || !b || !c || !d) continue;
		if (used[a][b][c][d]) continue;
		used[a][b][c][d] = used[b][c][d][a] = used[c][d][a][b] = used[d][a][b][c] = 1;
		cnt++;
	}
	cout << cnt;
	return 0;
}