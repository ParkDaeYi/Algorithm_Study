#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, string> pis;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<pis> v[51];
	while (n--) {
		string str; cin >> str;
		int sum = 0;
		for (int i = 0;i < str.length();++i) {
			if ('0' <= str[i] && str[i] <= '9') sum += str[i] - '0';		
		}
		v[str.length()].emplace_back(pis(sum, str));
	}
	for (int i = 1;i < 51;++i) {
		if (!v[i].size()) continue;
		sort(v[i].begin(), v[i].end());
		for (pis e : v[i]) cout << e.second << '\n';
	}
	return 0;
}