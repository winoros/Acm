/*
 * =====================================================================================
 *
 *       Filename:  23E.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/9/26 16:22:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

using namespace std;

const int base = 1000;
const int digit = 3;

class bign {
private:
    int _arr[110];
    int _m;
    void _simplify (void);
public:
    bign (void);
    bign (int init);
    friend istream& operator >> (istream& fin, bign& a);
    friend ostream& operator << (ostream& fout, const bign& a);
    friend bign operator + (bign a, const bign& b);
    friend bign operator + (bign a, int b);
    friend bign operator * (const bign& a, const bign& b);
    friend bign operator * (bign a, int b);
    friend bign operator / (bign a, int b);
    friend int operator % (bign a, int b);
    friend bool operator == (const bign& a, const bign& b);
    friend bool operator < (const bign& a, const bign& b);
    friend bool operator <= (const bign& a, const bign& b);
    friend bool operator > (const bign& a, const bign& b);
    friend bool operator >= (const bign& a, const bign& b);
};
void bign::_simplify (void) {
    for (int i = 0; i <= _m; i++) {
        if (i == _m && _arr[i] >= base) _m++;
        _arr[i + 1] += _arr[i] / base;
        _arr[i] %= base;
    }
}
bign::bign (void) : _m(0) { memset(_arr, 0, sizeof(_arr)); }
bign::bign (int init) : _m(0) {
    memset(_arr, 0, sizeof(_arr));
    _arr[0] = init;
    _simplify();
}
istream& operator >> (istream& fin, bign& a) {
    char init[10010]; int len, b, t;
    fin >> init;
    len = strlen(init); a._m = -1;
    for (int i = len - 1; i >= 0;) {
        t = 0, b = 1;
        for (int j = 0; j < digit && i >= 0; j++, i--) {
            t += (init[i] - '0') * b;
            b *= 10;
        }
        a._arr[++a._m] = t;
    }
    return fin;
}
ostream& operator << (ostream& fout, const bign& a) {
    fout << a._arr[a._m];
    for (int i = a._m - 1; i >= 0; i--)
        fout << setfill('0') << setw(digit) << a._arr[i];
    return fout;
}
bign operator + (bign a, const bign& b) {
    if (a._m < b._m) a._m = b._m;
    for (int i = 0; i <= b._m; i++)
        a._arr[i] += b._arr[i];
    a._simplify();
    return a;
}
bign operator + (bign a, int b) {
    a._arr[0] += b;
    a._simplify();
    return a;
}
bign operator * (const bign& a, const bign& b) {
    bign ans;
    ans._m = a._m + b._m;
    for (int i = 0; i <= a._m; i++)
    {
        for (int j = 0; j <= b._m; j++)
            ans._arr[i + j] += a._arr[i] * b._arr[j];
    }
    ans._simplify();
    return ans;
}
bign operator * (bign a, int b) {
    for (int i = 0; i <= a._m; i++)
        a._arr[i] *= b;
    a._simplify();
    return a;
}
bign operator / (bign a, int b) {
    for (int i = a._m; i >= 0; i--) {
        if (a._arr[i] < b && i == a._m && i != 0) a._m--;
        if (i > 0) a._arr[i - 1] += (a._arr[i] % b) * base;
        a._arr[i] /= b;
    } return a;
}
int operator % (bign a, int b) {
    for (int i = a._m; i >= 0; i--) {
        if (i == 0) return a._arr[i] % b;
        else a._arr[i - 1] += (a._arr[i] % b) * base;
    }
}
bool operator == (const bign& a, const bign& b) {
    if (a._m != b._m) return false;
    for (int i = 0; i <= a._m; i++)
        if (a._arr[i] != b._arr[i]) return false;
    return true;
}
bool operator < (const bign& a, const bign& b) {
	if (a._m != b._m) return a._m < b._m;
	for (int i = a._m; i >= 0; i--)
		if (a._arr[i] != b._arr[i]) return a._arr[i] < b._arr[i];
	return false;
}
bool operator <= (const bign& a, const bign& b) {
	if (a._m != b._m) return a._m < b._m;
	for (int i = a._m; i >= 0; i--)
		if (a._arr[i] != b._arr[i]) return a._arr[i] < b._arr[i];
	return true;
}
bool operator > (const bign& a, const bign& b) {
	return !(a <= b);
}
bool operator >= (const bign& a, const bign& b) {
	return !(a < b);
}

int tail[710], to[710<<1], pre[710<<1], tot;

inline void add(int _from, int _to) {
	pre[tot] = tail[_from];
	to[tot] = _to;
	tail[_from] = tot++;
}

bign dp[710][710];

int dfs(int now, int fa) {
	int son_cnt = 1;
	dp[now][0] = 0;
	dp[now][1] = 1;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		int _to = to[i];
		if(_to == fa)
			continue;
		int cnt = dfs(_to, now);
		for(int j = son_cnt; j > 0; --j)
			for(int k = cnt; k >= 0; --k)
				dp[now][j+k] = max(dp[now][j+k], dp[_to][k] * dp[now][j]);
		/* 
		for(int i = son_cnt + cnt; i >= 0; --i) {
			for(int j = 0; j <= cnt && j <= i; ++j) {
				dp[now][i] = max(dp[now][i], dp[_to][j] * dp[now][i-j]);
			}
		}
		*/
		son_cnt += cnt;
	}
	for(int i = 1; i <= son_cnt; i++)
		dp[now][0] = max(dp[now][i]*i, dp[now][0]);
	return son_cnt;
}

int main() {
	int n;
	scanf("%d", &n);
	tot = 0;
	memset(tail, -1, sizeof tail);
	for(int i = 1; i < n; i++) {
		int _u, _v;
		scanf("%d%d", &_u, &_v);
		add(_u, _v);
		add(_v, _u);
	}
	dfs(1, -1);
	cout << dp[1][0] << '\n';
	return 0;
}
