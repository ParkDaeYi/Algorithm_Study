#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, sum;
vector<int> arr;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (cin >> n) {
		if (n == -1) break;
		for (int i = 1; i <= n / 2; ++i) {
			if (n % i) continue;
			arr.push_back(i);
			sum += i;
		}
		cout << n;
		if (sum == n) {
			sort(arr.begin(), arr.end());
			cout << " = ";
			for (int i = 0; i < arr.size() - 1; ++i) cout << arr[i] << " + ";
			cout << arr[arr.size() - 1];
			cout << '\n';
		}
		else cout << " is NOT perfect.\n";
		sum = 0;
		arr.clear();
	}
	return 0;
}