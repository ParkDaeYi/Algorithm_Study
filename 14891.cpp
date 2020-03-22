#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

deque<int> gear[4];
bool visit[4];
int n;

void solve(int num, int ord) {
	int prv = num - 1, nxt = num + 1, cur = num;
	visit[cur] = 1;

	if (prv >= 0 && !visit[prv]) {
		if (gear[prv][2]!= gear[cur][6]) solve(prv, -ord);
	}
	if (nxt < 4 && !visit[nxt]) {
		if (gear[nxt][6] != gear[cur][2]) solve(nxt, -ord);
	}

	if (ord == 1) {
		int tmp = gear[cur].back();
		gear[cur].pop_back();
		gear[cur].push_front(tmp);
	}
	else {
		int tmp = gear[cur].front();
		gear[cur].pop_front();
		gear[cur].push_back(tmp);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 4; ++i) {
		char tmp;
		for (int j = 0; j < 8; ++j) {
			cin >> tmp;
			gear[i].push_back(tmp - '0');
		}
	}

	cin >> n;
	for (int i = 0, num, ord; i < n; ++i) {
		cin >> num >> ord;
		solve(num - 1, ord);
		fill(visit, visit + 4, 0);
	}

	int ans = 0;
	for (int i = 0; i < 4; ++i) {
		if (gear[i][0]) ans += pow(2, i);
	}
	cout << ans;
	return 0;
}