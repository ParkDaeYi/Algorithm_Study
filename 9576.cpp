#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int t, n, m;
bool visited[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		bool visited[1001] = { 0, };
		pii book[1001];
		for (int i = 0; i < m; ++i) cin >> book[i].first >> book[i].second;
		sort(book, book + m, [](const pii& p1, const pii& p2) {
			if (p1.second == p2.second) return p1.first < p2.first;
			else return p1.second < p2.second;
		});
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = book[i].first; j <= book[i].second; ++j) {
				if (!visited[j]) {
					++ans;
					visited[j] = 1;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}