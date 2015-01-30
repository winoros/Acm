/*
 * =====================================================================================
 *
 *       Filename:  3070.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/30 20:23:34
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

typedef vector<int> vec;
typedef vector<vec> mat;

const int mod = 1e4;

mat multiply(const mat &lhs, const mat &rhs) {
	mat ret(lhs.size(), vec(rhs[0].size()));
	int isz = lhs.size(), jsz = rhs[0].size(), ksz = rhs.size();
	for(int i = 0; i < isz; ++i)
		for(int j = 0; j < jsz; ++j) {
			long long tmp = 0;
			for(int k = 0; k < ksz; ++k)
				tmp += lhs[i][k] * rhs[k][j];
			ret[i][j] = tmp %mod;
		}
	return ret;
}

mat fast_pow(mat base, int idx) {
	mat ret(base.size(), vec(base.size()));
	for(int i = 0; i < base.size(); ++i)
		ret[i][i] = 1;
	while(idx) {
		if(idx&1)
			ret = multiply(ret, base);
		base = multiply(base, base);
		idx >>= 1;
	}
	return ret;
}

void MAIN(int n) {
	mat a(2, vec(2));
	a[0][0] = 1, a[0][1] = 1, a[1][0] = 1, a[1][1] = 0;
	a = fast_pow(a, n);
	printf("%d\n", a[1][0]);
}

int main() {
	int n;
	while(scanf("%d", &n) && n != -1)
		MAIN(n);
	return 0;
}
