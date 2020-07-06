#include <iostream>
#include <queue>
#include <algorithm>
#define m first	// 무게
#define v second	// 가격
using namespace std;
typedef pair<int, int> pii;
typedef long long int llt;

int n, k, knap[300000];
pii sack[300000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0;i < n;++i) cin >> sack[i].m >> sack[i].v;	
	for (int i = 0;i < k;++i) cin >> knap[i];
	// 보석의 사이즈에 맞는 배낭 중 가장 큰 가격을 가진 보석을 찾기 위해 정렬
	sort(knap, knap + k);
	sort(sack, sack + n);
	priority_queue<int, vector<int>, less<int>> pq;	// 내림차순
	llt ans = 0;
	for (int i = 0, j = 0;i < k;++i) {
		while (j < n && knap[i] >= sack[j].m) // 가방의 크기 >= 보석의 무게
			pq.push(sack[j++].v);
		if (!pq.empty()) {
			ans += pq.top();	// 현재 가방의 크기에 들어갈 수 있는 보석 중 가장 비싼 보석
			pq.pop();
		}
	}
	cout << ans;
	return 0;
}