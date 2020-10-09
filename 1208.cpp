#include <iostream>
#define VMAX 4000000
using namespace std;
typedef long long ll;

int N, S, arr[41], m, mp[VMAX*2 + 2];
ll ans;

// 부분 수열의 합을 구하는데 1<<N 의 시간이 걸림
// 그래서 절반으로 나눠서 1<<N/2 로 시간을 줄임
// check 배열인 mp을 사용하여 S - sum 으로 개수를 구함
// (Left)sum: 왼쪽 배열의 부분 수열의 값을 카운트
// (Right)S-sum: S에 현재 sum을 뺏을 때 mp 배열에 값이 있는 경우가
//				부분 수열의 합이 S가 되는 경우임

// Left
void dfs1(int idx, int sum) {
	if (idx == m) {
		mp[VMAX + sum]++; return;
	}
	dfs1(idx + 1, sum);
	dfs1(idx + 1, sum + arr[idx]);
}
// Right
void dfs2(int idx, int sum) {
	if (idx == N) {
		ans += mp[VMAX + S - sum]; return;
	}
	dfs2(idx + 1, sum);
	dfs2(idx + 1, sum + arr[idx]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> S;
	for (int i = 0;i < N;++i) cin >> arr[i];
	m = N / 2;
	dfs1(0, 0);
	dfs2(m, 0);
	if (!S) --ans;
	cout << ans;
	return 0;
}