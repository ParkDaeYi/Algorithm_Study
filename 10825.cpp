#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct SCORE {
	int a, b, c;
	string name;
	bool operator<(const SCORE& s) const {
		if (a == s.a && b == s.b && c == s.c) return name < s.name;
		else if (a == s.a && b == s.b) return c > s.c;
		else if (a == s.a) return b < s.b;
		return a > s.a;
	}
} s[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i = 0;i < n;++i) cin >> s[i].name >> s[i].a >> s[i].b >> s[i].c;
	sort(s, s + n);
	for (int i = 0;i < n;++i) cout << s[i].name << '\n';
	return 0;
}