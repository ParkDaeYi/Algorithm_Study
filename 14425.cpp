#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int n, m, ans;
unordered_set<string> s;
string str;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0;i < n;++i) {
		cin >> str;
		s.insert(str);
	}
	for (int i = 0;i < m;++i) {
		cin >> str;
		if (s.find(str) == s.end()) continue;
		ans++;
	}
	cout << ans;
	return 0;
}

//요건 트라이 연습
//#include <iostream>
//#include <string>
//#include <memory.h>
//using namespace std;
//
//class Trie {
//private:
//	Trie* nxt[26];
//	bool term;
//public:
//	Trie() : term(0) {
//		memset(nxt, 0, sizeof(nxt));
//	}
//	void insert(const char* key) {
//		if (*key == '\0') term = 1;
//		else {
//			int cur = *key - 'a';
//			if (nxt[cur] == NULL) nxt[cur] = new Trie();
//			nxt[cur]->insert(key + 1);
//		}
//	}
//	bool find(const char* key) {
//		if (*key == '\0' && term) return 1;
//		if (*key == '\0') return 0;
//		int cur = *key - 'a';
//		return nxt[cur] == NULL ? 0 : nxt[cur]->find(key + 1);
//	}
//};
//int n, m, ans;
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//
//	cin >> n >> m;
//	Trie* root = new Trie();
//	string str;
//	for (int i = 0;i < n;++i) {
//		cin >> str;
//		root->insert(&str[0]);
//	}
//	for (int i = 0;i < m;++i) {
//		cin >> str;
//		ans += root->find(&str[0]);
//	}
//	cout << ans;
//
//	return 0;
//}