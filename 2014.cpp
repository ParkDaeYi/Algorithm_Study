#include <iostream>
#include <queue>
using namespace std;
typedef long long int llt;

int n, k, arr[100000];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> arr[i], pq.push(arr[i]);
	int max_ele = arr[n - 1];	// max를 사용하여 연산 제어
	while (--k) {
		llt t = pq.top(); pq.pop();
		for (int i = 0; i < n; ++i) {
			llt tmp = t * arr[i];
			if (tmp >> 31) break;	// 정답은 2^31보다 작은 자연수
			if (max_ele < tmp) {
				if (pq.size() > k) break;	// k보다 pq의 사이즈가 클 필요가 없음
				max_ele = tmp;
			}
			pq.push(tmp);
			if (t % arr[i] == 0) break;	// 겹치는 숫자 발생을 막기 위함
		}
	}
	cout << pq.top();
	return 0;
}