// 이분 탐색(파라메트릭 서치)
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, l, arr[103];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> l;
	for (int i = 1;i <= n;++i) cin >> arr[i];
	sort(arr, arr + n + 1);
	arr[n + 1] = l;
	int s = 1, e = l - 1;
	while (s <= e) {
		int cnt = 0;
		int mid = s + e >> 1;
		// -1 하는 이유:
		// mid 가 50 이고 arr[i]-arr[i-1] 이 100일 때 / mid를 하면 2가 됨
		// 근데 arr[i]가 200이고 arr[i-1] 100이라 가정한다면
		// 100 150 200 으로 하나만 지으면 됨
		for (int i = 1;i < n + 2;++i) cnt += (arr[i] - arr[i - 1] - 1) / mid;
		if (cnt > m) s = mid + 1;
		else e = mid - 1;
	}
	cout << s;
	return 0;
}

// 우선순위 큐
#include <queue>
#include <vector>
typedef pair<double, int> pdi;

int n, m, l;
vector<int> v;

int main_2() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> l;
	v.emplace_back(0);
	for (int i = 0, x;i < n;++i) cin >> x, v.emplace_back(x);
	v.emplace_back(l);
	sort(v.begin(), v.end());
	priority_queue<pdi, vector<pdi>, less<pdi>> pq;
	for (int i = 1;i < n + 2;++i) pq.push(pdi(v[i] - v[i - 1], 1));
	while (m--) {
		double dist = pq.top().first; int cnt = pq.top().second;
		pq.pop();
		dist *= cnt;
		++cnt;
		pq.push(pdi(dist / cnt, cnt));
	}
	double dans = pq.top().first;
	int ians = (int)pq.top().first;
	cout << ians + !(dans == ians);
	return 0;
}