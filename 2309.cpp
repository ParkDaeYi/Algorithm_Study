#include <iostream>
#include <algorithm>
using namespace std;

int high[9], sum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; ++i) {
		cin >> high[i];
		sum += high[i];
	}
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (sum - high[i] - high[j] == 100) {
				high[i] = high[j] = -1;
				sort(high, high + 9);
				for (int k = 2; k < 9; ++k) cout << high[k] << '\n';
				return 0;
			}
		}
	}
}
