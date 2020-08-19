#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, m;
unordered_map<string, int> arr;
vector<string> ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	string s;
	while (n--) {
		cin >> s;
		arr[s] = 1;
	}
	while (m--) {
		cin >> s;
		if (arr.find(s) == arr.end()) continue;
		ans.push_back(s);
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (string& str : ans) cout << str << '\n';
	return 0;
}

// map 대신 arr를 vector<string>으로 선언해서 이분 탐색으로 풀어도 됨
// => 나는 arr.resize에서 런타임 에러가 떠서 그냥 map으로 품