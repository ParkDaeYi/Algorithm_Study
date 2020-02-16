#include <iostream>
#include <vector>
using namespace std;

const int MAX = 4000000;
int key, ans, cnt;
bool arr[MAX] = { 0,1 };
vector<int> prime;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> key;

	for (int i = 2; i * i < MAX; ++i) {
		if (!arr[i]) {
			for (int j = i * i; j < MAX; j += i) {
				if (!arr[j]) arr[j] = 1;
			}
		}
	}

	for (int i = 2; i < MAX; ++i) {
		if (!arr[i]) prime.push_back(i);
	}

	int low = 0, high = 0, sum = 0, sz = prime.size();

	while (low <= high && high < sz && prime[low] <= key) {
		if (sum < key) sum += prime[high++];		
		else if (sum == key) {
			ans++;
			sum += prime[high++];
		}
		else {
			sum -= prime[low++];
			if (low > high && low < prime.size()) {
				high = low;
				sum = prime[low];
			}
		}
	}
	cout << ans;
	return 0;
}
