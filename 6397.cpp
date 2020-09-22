// 입출력 뭣같은거 빼면 그냥 분할정복 문제
#include <iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;

int r, c, map[201][201], idx;
char op;
string order, ans;

void B(int r1, int c1, int r2, int c2) {
	if (r1 == r2 || c1 == c2) return;
	int x = map[r1][c1];
	bool flag = 0;
	for (int i = r1;i < r2;++i) {
		for (int j = c1;j < c2;++j) {
			if (x ^ map[i][j]) {
				flag = 1; break;
			}
		}
		if (flag) break;
	}
	if (flag) {
		ans += 'D';
		int rm = (r2 - r1) / 2 + (r2 - r1) % 2;
		int cm = (c2 - c1) / 2 + (c2 - c1) % 2;
		B(r1, c1, r1 + rm, c1 + cm);
		B(r1, c1 + cm, r1 + rm, c2);
		B(r1 + rm, c1, r2, c1 + cm);
		B(r1 + rm, c1 + cm, r2, c2);
	}
	else ans += '0' + x;
}

void D(int r1, int c1, int r2, int c2) {
	if (r1 == r2 || c1 == c2) { --idx; return; }
	if (idx == order.length()) return;
	if (order[idx] == 'D') {
		int rm = (r2 - r1) / 2 + (r2 - r1) % 2;
		int cm = (c2 - c1) / 2 + (c2 - c1) % 2;
		++idx; D(r1, c1, r1 + rm, c1 + cm);
		++idx; D(r1, c1 + cm, r1 + rm, c2);
		++idx; D(r1 + rm, c1, r2, c1 + cm);
		++idx; D(r1 + rm, c1 + cm, r2, c2);
	}
	else {
		for (int i = r1;i < r2;++i) for (int j = c1;j < c2;++j) map[i][j] = order[idx] - '0';
	}
}

// 오른쪽 정렬
// printf 썼으면 쉬웠을텐데 걍 일케함
int spc(int& x) {
	int tmp = x;
	while (tmp < 1000) {
		cout << ' ';
		tmp *= 10;
	}
	return x;
}

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (cin >> op) {
		if (op == '#') break;
		order = "";
		cin >> r >> c;
		string tmp;
		while (1) {
			cin >> tmp;
			order += tmp;
			if (tmp.length() < 50) break;
		}
		if (op == 'B') {
			ans = "";
			for (int s = 0, i = 0, j = 0;s < order.length();++s) {
				map[i][j++] = order[s] - '0';
				if (j == c) {
					++i;
					j = 0;
				}
			}
			B(0, 0, r, c);
			cout << 'D';
		}
		else {
			idx = 0;
			D(0, 0, r, c);
			cout << 'B';
		}
		cout << spc(r);
		cout << spc(c) << '\n';
		int cnt = 0;
		if (op == 'B') {
			for (int i = 0; i < ans.length();++i) {
				if (cnt++ == 50) cnt = 1, cout << '\n';
				cout << ans[i];
			}
		}
		else {
			for (int i = 0;i < r;++i) for (int j = 0;j < c;++j) {
				if (cnt++ == 50) cnt = 1, cout << '\n';
				cout << map[i][j];
			}
		}
		cout << '\n';
	}
	return 0;
}