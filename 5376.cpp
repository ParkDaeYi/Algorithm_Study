#include <iostream>
#include <string>
using namespace std;
typedef long long int llt;

int t;
string n;

llt gcd(llt a, llt b) { return b ? gcd(b, a % b) : a; }

void solve_1() {

	cin >> t;
	while (t--) {
		cin >> n;
		int idx = 2, cnt1 = 0, cnt2 = 0, sz = n.size();
		// cnt1: 비순환 소수 자릿수, cnt2: 순환 소수 자릿수
		llt A = 0, B = 0;	// A: 분자, B: 분모

		// 비순환 소수
		while (idx != sz) {
			if (n[idx] == '(') break;
			A = A * 10 + (n[idx++] - '0');
		}
		cnt1 = idx - 2;

		// 순환 소수
		llt tmp = A;
		while (idx != sz) {
			if (n[++idx] == ')') break;
			A = A * 10 + (n[idx] - '0');
			cnt2++;
		}
		// A와 tmp가 다르면 순환 소수 有, 순환 소수의 경우 10^n 이 아닌 9 * 10^(n-1)로 계산
		// 분자: (정수 + 순환 소수 끝자리) - (정수 - 순환하지 않는 부분)
		if (A != tmp) A -= tmp;	// 그러므로 현재 분자에 기존의 순환 소수 값을 빼줌

		// 분모: 순환 소수 자리 수만큼 9을 찍고 비순환 소수 자리 수만큼 0 추가
		while (cnt2--) B = B * 10 + 9;	// 순환 소수 9 * 10^(n-1)로 계산
		if (!B) B = 1; // 순환 소수가 없을 경우 B = 1로 지정
		while (cnt1--) B *= 10;	// 비순환 소수는 분모 * 10
		llt g = gcd(B, A);
		cout << A / g << '/' << B / g << '\n';
	}

}

int t;
string n;

llt gcd(llt a, llt b) { return b ? gcd(b, a % b) : a; }

void solve_2() {

	cin >> t;
	while (t--) {
		cin >> n;
		int i, sz = n.size();
		llt A, B, a, b;	// (A, B): 분자, (a, b): 분모 
		// 비순환 소수
		for (i = 2, a = 1, A = 0; i < sz && n[i] != '('; ++i, a *= 10) A = A * 10 + n[i] - '0';
		// 순환 소수
		for (i += n[i] == '(', b = 1, B = 0; i < sz && n[i] != ')'; ++i, b *= 10) B = B * 10 + n[i] - '0';
		// 순환 소수의 경우 10^n - 1 을 통해 9 * 10^(n-1)로 변경 
		b -= b > 1; A = B + A * b;	// A를 9 * 10^(n-1)에 맞춰 줌
		a *= b;	// 분모도 분자와 마찬가지
		llt g = gcd(A, a);
		cout << A / g << '/' << a / g << '\n';
	}

}