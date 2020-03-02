#include <iostream>
#include <queue>
#include <stack>
#define MAX 10000
using namespace std;

int visited[MAX], src, dest, t;
char dslr[MAX];

int D(int);
int S(int);
int L(int);
int R(int);
void bfs();

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		fill(visited, visited + MAX, -1);
		cin >> src >> dest;
		if (src != dest) bfs();
		stack<char> ans;
		while (src != dest) {
			ans.push(dslr[dest]);
			dest = visited[dest];
		}
		while (!ans.empty()) {
			cout << ans.top();
			ans.pop();
		}
		cout << '\n';	
	}
	return 0;
}

void bfs() {
	queue<int> q;
	q.push(src);
	visited[src] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int d = D(cur), s = S(cur), l = L(cur), r = R(cur);
		if (visited[d] == -1) {
			visited[d] = cur;
			dslr[d] = 'D';
			q.push(d);
		}
		if (visited[s] == -1) {
			visited[s] = cur;
			dslr[s] = 'S';
			q.push(s);
		}
		if (visited[l] == -1) {
			visited[l] = cur;
			dslr[l] = 'L';
			q.push(l);
		}
		if (visited[r] == -1) {
			visited[r] = cur;
			dslr[r] = 'R';
			q.push(r);
		}
		if (d == dest || s == dest || l == dest || r == dest) return;
	}
}

int D(int num) {
	return (num + num) % MAX;
}
int S(int num) {
	return num == 0 ? 9999 : num - 1;
}
int L(int num) {
	int t = (int)(num / 1000);
	return (num % 1000) * 10 + t;
}
int R(int num) {
	int t = num % 10;
	return t * 1000 + (int)(num / 10);
}