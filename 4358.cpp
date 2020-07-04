#include <iostream>
#include <memory.h>
#pragma warning(disable:4996)
using namespace std;

char tree[31];
int t_cnt;

class Trie {
private:
	Trie* ascii[128];
	int cnt;
public:
	Trie() :cnt(0) {
		memset(ascii, 0, sizeof(ascii));
	}
	void insert(const char* key) {
		if (*key == '\0') {	// 문자열 끝
			cnt++;	// 해당 나무 개수 카운트
			t_cnt++;	// 전체 나무 개수 카운트
			return;
		}
		int nxt = *key;
		if (!ascii[nxt]) ascii[nxt] = new Trie();
		ascii[nxt]->insert(key + 1);
	}
	void print(int idx = 0) {
		if (cnt) {
			tree[idx] = '\0';	// 저장된 문자열만 출력하기 위해서 널('\0') 삽입
			cout << tree << ' ' << 100.0 * cnt / t_cnt << '\n';
		}
		for (int i = 0; i < 128; ++i) {
			if (ascii[i]) {
				tree[idx] = i;	// 순서대로 문자열 저장
				ascii[i]->print(idx + 1);
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);

	cout << fixed;
	cout.precision(4);
	Trie* root = new Trie();
	while (cin.getline(tree, 31)) root->insert(tree);
	root->print();
	return 0;
}

#include <map>
#include <string>

void solve_2() {
	map<string, int> tree;
	string str;
	int t = 0;
	while (getline(cin, str)) {
		tree[str]++;	// 해당 나무 개수 (key 값에 str이 없더라도 자동으로 insert 됨)
		t++;	// 전체 나무 개수
	}
	cout << fixed;
	cout.precision(4);
	for (auto e : tree) cout << e.first << ' ' << 100.0 * e.second / t << '\n';
}