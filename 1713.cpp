#include <iostream>
#include <map>
using namespace std;
typedef pair<int, int> pii;

int n, k;
map<int, pii> mp;	// unordered_map은 자동 정렬이 안되므로 map 사용

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0, x; i < k; ++i) {
		cin >> x;
		// 후보가 없는 경우
		if (mp.find(x) == mp.end()) {
			if (mp.size() < n) mp[x] = { 1,i };	// 투표 수: 1, 게시된 시간: i
			else {
				// 사진틀이 꽉 찼을 경우
				int num = mp.begin()->first;
				pii info = mp.begin()->second;
				// 투표 수 혹은 게시된 지 가장 오래 된 사진을 찾음
				for (auto v : mp) {
					if (v.second < info) {
						num = v.first;
						info = v.second;
					}
				}
				mp.erase(num);	// 투표 수 혹은 게시된 지 가장 오래 된 사진 삭제
				mp[x] = { 1,i };	// 새로운 학생 추가
			}
		}
		// 후보가 있을 시 투표 수 추가
		else mp[x].first++;
	}
	for (auto ans : mp) cout << ans.first << ' ';
	return 0;
}