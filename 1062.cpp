#include <iostream>
#include <string>
using namespace std;

int n, k, ans;
string str[51];
bool visit[26];

void dfs(int depth, int idx) {
	// 주어진 문자만큼 가르침
	if (depth == k) {
		int ret = 0;
		for (int i = 0; i < n; ++i) {
			bool flag = 1;
			for (char c : str[i]) {
				if (!visit[c - 'a']) {
					flag = 0;
					break;
				}
			}
			if (flag) ret++;
		}
		ans = ans < ret ? ret : ans;
		return;
	}

	// 흔한 백트랙킹
	// idx를 사용하여 시간 초과 방지
	for (int i = idx; i < 26; ++i) {
		if (!visit[i]) {
			visit[i] = 1;
			dfs(depth + 1, i + 1);
			visit[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	if (k < 5) { cout << 0; return 0; }	// anta와 tica에 사용한 문자는 5개이므로 k는 최소 5여야 한다
	else if (k == 26) { cout << n; return 0; } // k가 26개이면 모든 문자를 가르칠 수 있음
	for (int i = 0; i < n; ++i) {
		cin >> str[i];
		str[i] = str[i].substr(4, str[i].size() - 8);	// anta와 tica를 뺀 문자로 변경
	}
	visit['a' - 'a'] = visit['n' - 'a'] = visit['c' - 'a'] = visit['t' - 'a'] = visit['i' - 'a'] = 1;
	k -= 5;	// a, c, i, n, t를 이미 true로 변경하였으므로 5를 뺌
	dfs(0, 0);
	cout << ans;

	return 0;
}