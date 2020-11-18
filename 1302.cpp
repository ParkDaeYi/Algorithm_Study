#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> a;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, mx = 0; cin >> n;
	string str;
	for (int i = 0;i < n;++i) {
		cin >> str;
		++a[str];
	}
	for (pair<string, int> e : a) {
		if (mx < e.second) mx = e.second, str = e.first;
	}
	cout << str;
	return 0;
}