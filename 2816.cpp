#include <iostream>
#include <string>
using namespace std;

int n, kbs1 = -1, kbs2 = -1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	string s;
	for (int i = 0;i < n;++i) {
		cin >> s;
		if (s == "KBS1") kbs1 = i;
		else if (s == "KBS2") kbs2 = i + (kbs1 == -1 ? 1 : 0);
	}
	for (int i = 0;i < kbs1;++i) cout << '1';
	for (int i = 0;i < kbs1;++i) cout << '4';
	for (int i = 0;i < kbs2;++i) cout << '1';
	for (int i = 1;i < kbs2;++i) cout << '4';
	return 0;
}