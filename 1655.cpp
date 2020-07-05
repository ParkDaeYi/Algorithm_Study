#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	priority_queue<int, vector<int>, less<int>> max_pq;	// 출력용 변수(짝수 인덱스 저장)
	priority_queue<int, vector<int>, greater<int>> min_pq;	//홀수 인덱스 저장
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		if (i % 2) min_pq.push(x);
		else max_pq.push(x);
		if (!min_pq.empty() && max_pq.top() > min_pq.top()) {	// 출력하는 변수의 top이 더 클 경우
			int tmp = max_pq.top();
			max_pq.pop(); max_pq.push(min_pq.top());
			min_pq.pop(); min_pq.push(tmp);
		}
		// ex. 1 2 3 4 5 6 7 일 경우
		//	max		min
		//	1		2
		//	3	에서 2를 출력해야 하는데 max_pq.top()의 값은 3임
		// 그래서
		//	1		3
		//	2	로 변경해준다.
		cout << max_pq.top() << '\n';
	}
	return 0;
}