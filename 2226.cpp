#include <iostream>
#include <string>
using namespace std;

string A[1001];
int arr1[1001], arr2[1001], ans[1001];

string sum(string a, string b) {
	int idx = a.length(), carry = 0;
	for (int i = idx - 1;~i;--i) arr1[i] = a[i] - '0';
	for (int i = idx - 1;~i;--i) arr2[i] = b[i] - '0';
	for (int i = idx - 1;~i;--i) {
		ans[i] = (arr1[i] + arr2[i] + carry) % 10;
		carry = (arr1[i] + arr2[i] + carry) / 10;
	}
	string ret = "";
	if (carry) ret += carry + '0';
	for (int i = 0; i < idx;++i) ret += ans[i] + '0';
	return ret;
}

string sub(string a, string b) {
	int n1 = a[a.length() - 1] - '0';
	int n2 = b[0] - '0';
	if (n1 < n2) {
		string ret;
		for (int i = a.length() - 1;~i;--i) {
			int x = a[i] - '0';
			if (1 > x) a[i] = '9';		
			else {
				a[i] = x - 1 + '0';
				break;
			}
		}
		if (a[0] == '0') for (int i = 1;i < a.length();++i) ret += a[i];
		else for (int i = 0;i < a.length();++i) ret += a[i];
		return ret;
	}
	else {
		a[a.length() - 1] = n1 - 1 + '0';
		return a;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	A[1] = "0"; A[2] = A[3] = "1";
	for (int i = 4;i <= n;++i) {
		// A[i] = A[i - 1] * 2
		//  (i % 2) : - 1
		// !(i % 2) : + 1
		if (i % 2) A[i] = sub(sum(A[i - 1], A[i - 1]), "1");
		else {
			string t1 = sum(A[i - 1], A[i - 1]);
			string t2;
			for (int i = 0;i < t1.length() - 1;++i) t2 += '0';
			t2 += '1';
			A[i] = sum(t1, t2);
		}
	}
	cout << A[n];
	return 0;
}