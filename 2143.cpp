#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int llt;

int T, N, M, a[1000], b[1000];
vector<int> aa, bb;
llt ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T >> N;

	for (int n = 0; n < N; ++n) cin >> a[n];
	for (int i = 0; i < N; ++i) {
		int sum = a[i];
		aa.push_back(sum);
		for (int j = i + 1; j < N; ++j) {
			sum += a[j];
			aa.push_back(sum);
		}
	}
	cin >> M;
	for (int i = 0; i < M; ++ i) cin >> b[i];
	for (int i = 0; i < M; ++i) {
		int sum = b[i];
		bb.push_back(sum);
		for (int j = i + 1; j < M; ++j) {
			sum += b[j];
			bb.push_back(sum);
		}
	}
	sort(aa.begin(), aa.end());
	sort(bb.begin(), bb.end());
	int al = 0, br = bb.size() - 1;
	while (al < aa.size() && br >= 0) {
		llt sum = aa[al] + bb[br];
		int tmp;
		if (sum < T) {
			tmp = aa[al];
			while (al < aa.size() && aa[al] == tmp) al++;
		}
		else if (sum > T) {
			tmp = bb[br];
			while (br >= 0 && bb[br] == tmp) br--;
		}
		else {
			llt cntA = 0, cntB = 0;
			tmp = aa[al];
			while (al < aa.size() && aa[al] == tmp) { al++; cntA++; }
			tmp = bb[br];
			while (br >= 0 && bb[br] == tmp) { br--; cntB++; }
			ans += cntA * cntB;
		}
	}
	cout << ans;
	return 0;
}