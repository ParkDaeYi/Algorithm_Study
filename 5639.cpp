#include <iostream>
#pragma warning(disable:4996)
using namespace std;

int arr[1000000], idx;

void postOrder(int left, int right) {
	if (left > right) return;	// 기저 조건
	int& root = arr[left];
	int s = left, e = right;
	while (root <= arr[s]) s++;	// 현재 root의 왼쪽 자식
	while (root < arr[e]) e--;	// 현재 root의 왼쪽 자식 중 가장 큰 값
	postOrder(s, e);	// 왼쪽
	postOrder(e + 1, right);	// 오른쪽
	cout << root << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);

	int x;
	while (cin >> x) arr[idx++] = x;
	postOrder(0, idx - 1);

	return 0;
}