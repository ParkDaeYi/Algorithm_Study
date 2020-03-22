#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int t, f, parent[200000];

int getParent(int);
int uni(int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> f;
		fill(parent, parent + f * 2, -1);
		unordered_map<string, int> dic;
		for (int i = 1, idx = 1; i <= f; ++i) {
			string str1, str2;
			cin >> str1 >> str2;
			if (dic.find(str1) == dic.end()) dic[str1] = idx++;
			if (dic.find(str2) == dic.end()) dic[str2] = idx++;
			cout << -uni(dic[str1], dic[str2]) << '\n';
		}
	}
	return 0;
}

int getParent(int x) {
	if (parent[x] < 0) return x;
	return parent[x] = getParent(parent[x]);
}

int uni(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a != b) {
		parent[a] += parent[b];
		parent[b] = a;
	}
	return parent[a];
}