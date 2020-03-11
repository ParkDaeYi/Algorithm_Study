#include <iostream>
#include <queue>
#include <functional>
using namespace std;
typedef long long int llt;

int n, k, arr[100];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		pq.push(arr[i]);
	}
	int max = arr[n - 1];
	while (--k){
		llt s = pq.top(); pq.pop();
		for (int j = 0; j < n; j++)
		{
			llt t = s * arr[j];
			if (t >> 31) break;
			if (t > max)
			{
				if (pq.size() > k) break;
				max = t;
			}
			pq.push(t);
			if (s % arr[j] == 0) break;
		}
	}
	cout << pq.top();
	return 0;
}