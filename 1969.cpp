#include <iostream>
#include <string>
using namespace std;

int mem[50][4], n, m, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string dna;
		cin >> dna;
		for (int j = 0; j < m; ++j) {
			switch (dna[j]) {
			case 'A': mem[j][0]++; break;
			case 'C': mem[j][1]++; break;
			case 'G': mem[j][2]++; break;
			case 'T': mem[j][3]++; break;
			}
		}
	}
	string res = "";
	for (int i = 0; i < m; ++i) {
		int idx = 0, cnt = 0;
		for (int j = 0; j < 4; ++j) {
			if (mem[i][j] > cnt) {
				idx = j;
				cnt = mem[i][j];
			}
		}
		ans += n - cnt;
		switch (idx) {
		case 0: res += 'A'; break;
		case 1: res += 'C'; break;
		case 2: res += 'G'; break;
		case 3: res += 'T'; break;
		}
	}
	cout << res << '\n' << ans;
	return 0;
}