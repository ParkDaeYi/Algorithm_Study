#include <iostream>
#include <string>
#include <vector>
using namespace std;

string _key, arr[100];
int n, _keysz;

bool isTrue(int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> _key >> n;
	_keysz = _key.length();
	for (int i = 0; i < n; ++i) cin >> arr[i];
	if (isTrue(0)) cout << 1;
	else cout << 0;
	return 0;
}

bool isTrue(int cur) {
	if (cur == _keysz) return 1;
	for (int i = 0; i < n; ++i) {
		bool flag = 1;
		int sz = arr[i].length();
		for (int j = 0; j < sz; ++j) {
			if (cur + j == _keysz) {
				flag = 0; break;
			}
			if (arr[i][j] != _key[cur + j]) {
				flag = 0; break;
			}
		}
		if(flag) if (isTrue(cur + sz)) return 1;
	}
	return 0;
}