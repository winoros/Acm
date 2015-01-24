/*
 * =====================================================================================
 *
 *       Filename:  4686.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/24 18:23:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <cctype>
#include <climits>
#include <stack>
#include <cmath>
#include <bitset>
#include <numeric>
#include <functional>

using namespace std;

const int mod = 1e9+7;

struct matrix {
	int m[6][6];
	matrix() {
		memset(m, 0, sizeof m);
	}
	const matrix operator * (const matrix &rhs) {
		matrix ret;
		for(int i = 0; i < 6; ++i)
			for(int j = 0; j < 6; ++j) {
				long long sum = 0;
				for(int k = 0; k < 6; ++k)
					sum += (long long)m[i][k] * rhs.m[k][j] %mod;
				ret.m[i][j] = sum %mod;
			}
		return ret;
	}
};

matrix quick_pow(matrix m, long long pow) {
	matrix ret;
	for(int i = 0; i < 6; ++i)
		ret.m[i][i] = 1;
	while(pow) {
		if(pow&1)
			ret = ret * m;
		m = m * m;
		pow>>=1;
	}
	return ret;
}

void print(const matrix m) {
	puts("--------------");
	for(int i = 0; i < 6; ++i)
		for(int j = 0; j < 6; ++j)
			printf("%5d%c", m.m[i][j], j == 5 ? '\n' : ' ');
	puts("--------------");
}

void MAIN(long long n, int a0, int ax, int ay, int b0, int bx, int by) {
	matrix m;
	m.m[0][0] = ax, m.m[0][2] = 1;
	m.m[1][1] = bx, m.m[1][3] = 1;
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	m.m[4][0] = (long long)ax*by %mod, m.m[4][1] = (long long) bx*ay %mod, m.m[4][2] = by, m.m[4][4] = (long long)ax*bx %mod;
	m.m[5][4] = m.m[5][5] = 1;
	matrix mm = quick_pow(m, n);
	long long ans;
	ans = ((long long)mm.m[5][0]*a0 %mod + (long long)mm.m[5][1]*b0 %mod + (long long) mm.m[5][2]*ay %mod + (long long)mm.m[5][3]*by %mod + (long long) mm.m[5][4]*((long long)a0*b0 %mod) %mod) %mod;
	printf("%I64d\n", ans);
}

int main() {
	long long n;
	int a0, ax, ay, b0, bx, by;
	while(scanf("%I64d%d%d%d%d%d%d", &n, &a0, &ax, &ay, &b0, &bx, &by) > 0)
		MAIN(n, a0, ax, ay, b0, bx, by);
	return 0;

}
