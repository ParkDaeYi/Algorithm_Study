#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int llt;

class info {
public:
	int type, atk, hp;
};

int n, atk;
info room[123456];

bool isSafe(llt);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> atk;
	for (int i = 0; i < n; ++i) cin >> room[i].type >> room[i].atk >> room[i].hp;
	llt left = 1, right = 1e18, mid, ans = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (isSafe(mid)) {
			ans = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	cout << ans;
	return 0;
}

bool isSafe(llt mid) {
	llt cur_hp = mid, cur_atk = atk;
	for (int i = 0; i < n; ++i) {
		if (room[i].type == 1) {
			llt cnt = room[i].hp / cur_atk;
			if (room[i].hp % cur_atk) cnt++;
			cnt--;
			cur_hp -= cnt * room[i].atk;
			if (cur_hp <= 0) return 0;
		}
		else {
			cur_atk += room[i].atk;
			cur_hp = cur_hp + room[i].hp > mid ? mid : cur_hp + room[i].hp;
		}
	}
	return 1;
}