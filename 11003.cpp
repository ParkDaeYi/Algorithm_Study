#include <iostream>
#include <deque>
using namespace std;
typedef pair<int, int> pii;

int N, L, arr[5000000];
deque<pii> dq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; ++i) cin >> arr[i];

	for (int i = 0; i < N; ++i) {
		if (!dq.empty() && dq.front().second == i - L) dq.pop_front();	// L 사이즈를 유지해야 함
		while (!dq.empty() && dq.back().first > arr[i]) dq.pop_back();	// 사실상 새로 추가하는 숫자보다 큰 숫자는 필요 없음
		dq.push_back({ arr[i],i });
		cout << dq.front().first << ' ';
	}
	return 0;
}