#include <iostream>
#define MAX 105
using namespace std;

int t, c, v, arr[MAX][MAX], visit[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		int maxf = 0, fidx = 0, rmdc = 0, maxs = 0, sidx = 0;
		fill(visit, visit + 101, 0);
		cin >> c >> v;
		for (int i = 0; i < v; ++i) {
			for (int j = 0; j < c; ++j) cin >> arr[i][j];		
			visit[arr[i][0]]++;
		}
		for (int i = 1; i <= c; ++i) {
			if (maxf < visit[i]) {
				maxf = visit[i];
				fidx = i;
			}
		}
		if (maxf > v / 2) {
			cout << fidx << " 1\n";
			continue;
		}
		visit[fidx] = 0;
		for (int i = 1; i <= c; ++i) {
			if (maxs < visit[i]) {
				maxs = visit[i];
				sidx = i;
			}
		}
		fill(visit, visit + c + 1, 0);
		for (int i = 0; i < v; ++i) {
			for (int j = 0; j < c; ++j) {
				if (arr[i][j] == fidx || arr[i][j] == sidx) {
					visit[arr[i][j]]++;
					break;
				}
			}
		}
		visit[fidx] > visit[sidx] ? cout << fidx << " 2\n" : cout << sidx << " 2\n";
	}
	return 0;
}