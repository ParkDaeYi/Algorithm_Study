#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, arr[10];
bool visit[10];
vector<int> v;

void back(int idx, int num) {
	if (idx == k) v.push_back(num);
	else {
		for (int i = idx; i < n; ++i) {
			if (visit[i]) continue;
			visit[i] = 1;
			int x = num * 10;
			if (arr[i] > 9) x *= 10;	// arr[i]가 10 이상일 경우 x를 한 번 더 10으로 곱해줘야 함
			back(idx + 1, x + arr[i]);
			visit[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	// 백트랙킹을 통해 만들 수 있는 정수를 모두 만듦
	back(0, 0);
	// 만든 정수가 겹쳤을 수도 있으므로 중복 제거를 해줌
	sort(v.begin(), v.end());	// 정렬하고 erase(unique(),) 해야함
	v.erase(unique(v.begin(), v.end()), v.end());
	cout << v.size();
	return 0;
}