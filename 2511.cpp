#include <iostream>
using namespace std;

int arr[10], a, b, flag = 0;
// flag ==> A 승: 0, B 승: 1

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0;i < 10;++i) cin >> arr[i];
	for (int i = 0, c;i < 10;++i) {
		cin >> c;
		if (arr[i] == c) a++, b++;
		else if (arr[i] > c) a += 3, flag = 0;
		else b += 3, flag = 1;
	}
	cout << a << ' ' << b << '\n';
	if (a > b) cout << 'A';
	else if (a < b) cout << 'B';
	else if (a == 10 && b == 10) cout << 'D';
	else cout << (char)(flag + 'A');
	return 0;
}