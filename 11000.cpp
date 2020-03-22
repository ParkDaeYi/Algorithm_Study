#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> pii;

pii arr[200000];
int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n);
	pq.push(arr[0].second);
	for (int i = 1; i < n; ++i) {
		if (pq.top() <= arr[i].first) pq.pop();
		pq.push(arr[i].second);	
	}
	cout << pq.size();
	return 0;
}