#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int llt;

int N, ABCD[4][4000], AB[4000 * 4000 + 1], CD[4000 * 4000 + 1];
llt ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> ABCD[0][i] >> ABCD[1][i] >> ABCD[2][i] >> ABCD[3][i];

	int idx = 0;
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < N; ++j) {	// 투 포인터로 풀기 위해 두개의 배열로 만듦
			AB[idx] = ABCD[0][i] + ABCD[1][j];
			CD[idx++] = ABCD[2][i] + ABCD[3][j];
		}
	
	sort(AB, AB + idx);	// 투 포인터로 풀기 위해 정렬
	sort(CD, CD + idx);

	int AB_itr = 0, CD_itr = idx - 1;
	while (AB_itr < idx && CD_itr >= 0) {
		if (AB[AB_itr] + CD[CD_itr] > 0) {	// 0보다 클 경우 가장 큰 값에서 시작하는 CD_itr를 줄임
			int tmp = CD[CD_itr];
			while (tmp == CD[CD_itr] && CD_itr >= 0) CD_itr--;
		}
		else if (AB[AB_itr] + CD[CD_itr] < 0) {	// 0보다 작을 경우 가장 작은 값에서 시작하는 AB_itr를 줄임
			int tmp = AB[AB_itr];
			while (tmp == AB[AB_itr] && AB_itr < idx) AB_itr++;
		}
		else {
			llt AB_cnt = 0, CD_cnt = 0;
			int tmp = AB[AB_itr];
			while (tmp == AB[AB_itr] && AB_itr < idx) { AB_itr++; AB_cnt++; }
			tmp = CD[CD_itr];
			while (tmp == CD[CD_itr] && CD_itr >= 0) { CD_itr--; CD_cnt++; }
			ans += AB_cnt * CD_cnt;
		}
	}
	cout << ans;
	return 0;
}