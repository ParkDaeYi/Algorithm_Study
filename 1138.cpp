#include <iostream>
using namespace std;

int n, arr[10], l;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1;i < n + 1;++i) {
		cin >> l;
		for (int j = 0;j < n;++j) {
			if (!l && !arr[j]) {
				arr[j] = i;
				break;
			}
			else if (!arr[j]) l--;
		}
	}
	for (int i = 0;i < n;++i) cout << arr[i] << ' ';
	return 0;
}