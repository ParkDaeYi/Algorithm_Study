#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int T, n, p[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		unordered_map<string, int> idx;
		vector<int> v;
		string str, ans[1001];
		for (int i = 0;i < n;++i) {
			cin >> str;
			idx[str] = i;
		}
		for (int i = 0;i < n;++i) {
			cin >> str;
			v.emplace_back(idx[str]);
		}
		for (int i = 0;i < n;++i) {
			cin >> str;
			ans[v[i]] = str;
		}
		for (int i = 0;i < n;++i) cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}

int T, n, p[1001];

int main_2() {

	cin >> T;
	while (T--) {
		cin >> n;
		string str[3][1001], ans = "";
		for (int i = 0;i < 3;++i) for (int j = 0;j < n;++j) cin >> str[i][j];	
		for (int i = 0;i < n;++i) for (int j = 0;j < n;++j) {
			if (str[0][i] != str[1][j]) continue;
			p[i] = j; break;
		}
		for (int i = 0;i < n;++i) ans += str[2][p[i]] + ' ';	
		cout << ans << '\n';
	}
	return 0;
}