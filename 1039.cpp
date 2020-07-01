#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

string n;
int K, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> K;
	// 예외 처리
	if (n.size() == 1 || n.size() == 2 && stoi(n) % 10 == 0) { cout << -1;	return 0; }
	queue<string> q;
	q.push(n);
	while (!q.empty() && K--) {
		unordered_set<string> used;
		int qsz = q.size();
		for (int i = 0; i < qsz; ++i) {
			string tmp = q.front();
			q.pop();
			for (int j = 0; j < tmp.size() - 1; ++j) {
				for (int k = j + 1; k < tmp.size(); ++k) {
					if (j == 0 && tmp[j] == '0') continue;	// 첫 자리가 0으로 시작하면 안됨
					swap(tmp[j], tmp[k]);
					// 없는 숫자일 경우 추가
					if (used.find(tmp) == used.end()) {
						if (!K && ans < stoi(tmp)) ans = stoi(tmp);	// K 가 0일 경우 가장 큰 수를 찾음
						q.push(tmp);
						used.insert(tmp);
					}
					swap(tmp[j], tmp[k]);
				}
			}
		}
	}
	cout << (ans ? ans : -1);
	return 0;
}