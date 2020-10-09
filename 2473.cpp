// 투 포인터
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int N;
ll arr[5001], sum, mn = 3e9 + 1, ans[3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0;i < N;++i) cin >> arr[i];
	sort(arr, arr + N);
	// 변수 하나 고정 시킴
	for (int i = 0;i < N - 2;++i) {
		// i: min, l: mid, r: max
		int l = i + 1, r = N - 1;
		while (l < r) {
			sum = arr[i] + arr[l] + arr[r];
			if (mn > llabs(sum)) {
				mn = llabs(sum);
				ans[0] = arr[i], ans[1] = arr[l], ans[2] = arr[r];
			}
			if (sum < 0) ++l;
			else if (sum > 0) --r;
			else break;
		}
		if (!sum) break;
	}
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
	return 0;
}

// 파라메트릭 서치
#include <vector>

struct Point {
	ll a, b, c;
	Point() { a = b = c = 0; }
	Point(ll a, ll b, ll c) :a(a), b(b), c(c) {}
	bool operator<(Point& p) {
		ll x1 = a + b + c;
		ll x2 = p.a + p.b + p.c;
		return llabs(x1) < llabs(x2);
	}
	void print() {
		ll mn = min({ a,b,c });
		ll mx = max({ a,b,c });
		cout << mn << ' ' << a + b + c - mn - mx << ' ' << mx;
	}
}asdf;
int N;
vector<int> v;

int main_2() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	v.resize(N);
	for (int i = 0;i < N;++i) cin >> v[i];
	sort(v.begin(), v.end());
	asdf = Point(v[0], v[1], v[2]);
	for (int i = 0;i < N - 1;++i) {
		for (int j = i + 1;j < N;++j) {
			ll tmp = -(v[i] + v[j]);
			int idx = lower_bound(v.begin() + j + 1, v.end(), tmp) - v.begin();
			for (int k = idx - 1;k <= idx;++k) {
				if (j >= k || k >= N) continue;
				Point tmp = Point(v[i], v[j], v[k]);
				if (tmp < asdf) asdf = tmp;
			}
		}
	}
	asdf.print();
	return 0;
}