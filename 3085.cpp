#include <iostream>
#include <algorithm>
using namespace std;

char candy[50][50];
int n, _max, ans;

inline void _swap(char& a, char& b) {
	char tmp = a;
	a = b;
	b = tmp;
	return;
}
int Candy_MAX();

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> candy[i][j];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			_swap(candy[i][j], candy[i][j + 1]);
			ans = max(ans, Candy_MAX());
			_swap(candy[i][j], candy[i][j + 1]);

			_swap(candy[j][i], candy[j + 1][i]);
			ans = max(ans, Candy_MAX());
			_swap(candy[j][i], candy[j + 1][i]);
		}
	}
	cout << ans;
	return 0;
}

int Candy_MAX() {
	int ret = 1;
	for (int i = 0; i < n; ++i) {
		int tmp = 1;
		for (int j = 0; j < n - 1; ++j) {		
			if (candy[i][j] == candy[i][j + 1]) ++tmp;
			else {
				ret = ret > tmp ? ret : tmp;
				tmp = 1;
			}
			ret = ret > tmp ? ret : tmp;
		}
	}
	for (int i = 0; i < n; ++i) {
		int tmp = 1;
		for (int j = 0; j < n - 1; ++j) {	
			if (candy[j][i] == candy[j+1][i]) ++tmp;
			else {
				ret = ret > tmp ? ret : tmp;
				tmp = 1;
			}
			ret = ret > tmp ? ret : tmp;
		}
	}
	return ret;
}
