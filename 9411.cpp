#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#define MAXDIGITS 31
#define PLUS 1
#define MINUS -1
#pragma warning(disable:4996)
using namespace std;

class bignum {
public:
	bignum();
	~bignum();
	bignum(string str);
	bignum(const bignum* other);

	// 사칙 연산
	const bignum add(bignum& other);
	const bignum subtract(bignum& other);

	// 비교 연산
	int compare(const bignum& other) const;

	// -0 방지
	const void zero_justify();

	// 부호 연산
	const bignum operator-();
	const bignum operator+();

	// 대입 연산
	bignum& operator =(const bignum& other);
	bignum& operator +=(bignum& other);
	bignum& operator -=(bignum& other);

	// 출력 연산
	const string asString() const;

private:
	char digits[MAXDIGITS];
	char decpts[MAXDIGITS];
	int signbit;
	int lastdigit;
	int lastdecpt;
};
bignum::bignum() {
	lastdigit = 0;
	lastdecpt = 0;
	signbit = PLUS;
	for (int i = 0; i < MAXDIGITS; ++i) digits[i] = 0, decpts[i] = 0;
}
bignum::bignum(string str) {
	int eof = 0, len = str.size() - 1;
	if (str[0] == '-') {
		eof++;
		signbit = MINUS;
	}
	else {
		if (str[0] == '+') eof++;
		signbit = PLUS;
	}
	int i, j, dot;
	for (int i = 0;i <= len;++i) {
		if (str[i] == '.') {
			dot = i;
			break;
		}
	}
	lastdigit = dot - 1 - eof;
	lastdecpt = len - dot - 1;
	for (i = dot - 1, j = 0;i >= eof;--i) digits[j++] = str[i] - '0';
	for (;j < MAXDIGITS;++j) digits[j] = 0;

	for (i = dot + 1, j = 0;i <= len;++i) decpts[j++] = str[i] - '0';
	for (;j < MAXDIGITS;++j) decpts[j] = 0;
}
bignum::bignum(const bignum* other) {
	for (int i = 0; i < MAXDIGITS; ++i) digits[i] = other->digits[i], decpts[i] = other->decpts[i];
	lastdecpt = other->lastdecpt;
	lastdigit = other->lastdigit;
	signbit = other->signbit;
}
bignum::~bignum() {}

const bignum operator+(bignum& lhs, bignum& rhs) {
	return lhs.add(rhs);
}
const bignum operator-(bignum& lhs, bignum& rhs) {
	return lhs.subtract(rhs);
}
const void bignum::zero_justify() {
	while ((lastdigit > 0) && (digits[lastdigit] == 0)) lastdigit--;
	while ((lastdecpt > 0) && (decpts[lastdecpt] == 0)) lastdecpt--;
	if ((lastdigit == 0) && (digits[0] == 0)) signbit = PLUS;
}

const bignum bignum::add(bignum& other) {
	bignum ret;
	int carry;

	if (signbit == other.signbit) ret.signbit = signbit;
	else {
		if (signbit == MINUS) {
			signbit = PLUS;
			ret = other.subtract(*this);
			signbit = MINUS;
		}
		else {
			other.signbit = PLUS;
			ret = this->subtract(other);
			other.signbit = MINUS;
		}
		return ret;
	}

	ret.lastdecpt = max(lastdecpt, other.lastdecpt);
	carry = 0;

	for (int i = ret.lastdecpt; i >= 0; --i) {
		ret.decpts[i] = (char)(carry + decpts[i] + other.decpts[i]) % 10;
		carry = (carry + decpts[i] + other.decpts[i]) / 10;
	}
	digits[0] += carry;

	ret.lastdigit = max(lastdigit, other.lastdigit) + 1;
	carry = 0;

	for (int i = 0; i <= (ret.lastdigit); ++i) {
		ret.digits[i] = (char)(carry + digits[i] + other.digits[i]) % 10;
		carry = (carry + digits[i] + other.digits[i]) / 10;
	}
	ret.zero_justify();
	return ret;
}

const bignum bignum::subtract(bignum& other) {
	bignum ret;
	int borrow, v, i, j;

	if ((signbit == MINUS) || (other.signbit == MINUS)) {
		other.signbit = -1 * other.signbit;
		ret = this->add(other);
		other.signbit = -1 * other.signbit;
		return ret;
	}
	if (this->compare(other) == PLUS) {
		ret = other.subtract(*this);
		ret.signbit = MINUS;
		return ret;
	}

	if (lastdecpt < other.lastdecpt) i = ret.lastdecpt = other.lastdecpt;
	else {
		ret.lastdecpt = lastdecpt + 1;
		i = other.lastdecpt;
		for (int k = i + 1; k <= lastdecpt; ++k) ret.decpts[k] = decpts[k];
	}
	borrow = 0;
	for (;i >= 0;--i) {
		v = decpts[i] - borrow - other.decpts[i];
		if (v < 0) {
			v += 10;
			borrow = 1;
		}
		else borrow = 0;
		ret.decpts[i] += (char)v % 10;
	}
	digits[0] -= borrow;

	ret.lastdigit = max(lastdigit, other.lastdigit);
	borrow = 0;
	for (i = 0; i <= (ret.lastdigit); ++i) {
		v = digits[i] - borrow - other.digits[i];
		if (v < 0) {
			v += 10;
			borrow = 1;
		}
		else borrow = 0;
		ret.digits[i] += (char)v % 10;
	}
	ret.zero_justify();
	return ret;
}

int bignum::compare(const bignum& other) const {
	if ((signbit == MINUS) && (other.signbit == PLUS)) return PLUS;
	if ((signbit == PLUS) && (other.signbit == MINUS)) return MINUS;

	if (other.lastdigit > lastdigit) return PLUS * signbit;
	if (lastdigit > other.lastdigit) return MINUS * signbit;

	for (int i = lastdigit; i >= 0; --i) {
		if (digits[i] > other.digits[i]) return MINUS * signbit;
		if (other.digits[i] > digits[i]) return PLUS * signbit;
	}
	return 0;
}

const string bignum::asString() const {
	string ret = "";
	if (signbit == MINUS) ret += '-';
	for (int i = lastdigit; i >= 0; --i) ret += digits[i] + '0';
	if (lastdecpt == 0 && decpts[0] == 0) return ret;
	ret += '.';
	for (int i = 0; i <= lastdecpt; ++i) ret += decpts[i] + '0';
	return ret;
}

const bignum bignum::operator+() {
	return *this;
}
const bignum bignum::operator-() {
	signbit = signbit == PLUS ? MINUS : PLUS;
	return *this;
}
bignum& bignum::operator=(const bignum& other) {
	for (int i = 0; i < MAXDIGITS; ++i) digits[i] = other.digits[i], decpts[i] = other.decpts[i];
	lastdecpt = other.lastdecpt;
	lastdigit = other.lastdigit;
	signbit = other.signbit;
	return *this;
}
bignum& bignum::operator+=(bignum& other) {
	return *this = (*this) + other;
}
bignum& bignum::operator-=(bignum& other) {
	return *this = (*this) - other;
}

int t;
string str;
vector<bignum> arr;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		while (1) {
			cin >> str;
			if (str.size() == 1 && str[0] == '0') {
				bignum ret;

				for (int i = 0; i < arr.size(); ++i)
					ret += arr[i];

				string ans = ret.asString();
				cout << ans << '\n';

				arr.clear();
				break;
			}
			else arr.push_back(new bignum(str));
		}
	}

	return 0;
}