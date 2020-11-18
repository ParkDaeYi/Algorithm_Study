#include <iostream>
#include <unordered_map>
using namespace std;

// 이분탐색으로 해도 됨, 그게 더 빠름
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		unordered_map<int, int> map;
		for (int i = 0, x;i < n;++i) {
			cin >> x;
			++map[x];
		}
		cin >> n;
		while (n--) {
			int x; cin >> x;
			cout << (map.find(x) != map.end()) << '\n';
		}
	}
	return 0;
}