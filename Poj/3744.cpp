/*
 * =====================================================================================
 *
 *       Filename:  3744.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/11/4 14:40:27
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

struct matrix {
	double m[2][2];
	matrix() {}
	matrix(double a, double b, double c, double d) {
		m[0][0] = a, m[0][1] = b, m[1][0] = c, m[1][1] = d;
	}
	matrix operator * (const matrix b) {
		matrix ret(0, 0, 0, 0);
		for(int i = 0; i < 2; ++i)
			for(int j = 0; j < 2; ++j)
				for(int k = 0; k < 2; ++k)
					ret.m[i][j] += m[i][k]*b.m[k][j];
		return ret;
	}
};

matrix quick_pow(matrix a, int i) {
	if(!i)
		return matrix(1, 0, 0, 1);
	matrix ret = quick_pow(a, i>>1);
	ret = ret*ret;
	if(i&1)
		ret = ret*a;
	return ret;
}

int main() {
	int n, pos[15];
	double p;
	pos[0] = 0;
	while(scanf("%d%lf", &n, &p) > 0) {
		for(int i = 1; i <= n; ++i)
			scanf("%d", &pos[i]);
		sort(pos+1, pos+1+n);
		matrix a(0, 1, 1-p, p);
		double a1 = 1, a2 = p;
		for(int i = 1; i <= n; ++i) {
			if(pos[i] - pos[i-1] == 1) {
				a1 = 0;
				break;
			} else if(pos[i] - pos[i-1] == 2) {
				a1 *= 1-p;
				a2 = a1*p;
			} else if(pos[i] - pos[i-1] == 3) {
				a1 = a2*(1-p);
				a2 = a1*p;
			} else {
				matrix mul = quick_pow(a, pos[i] - pos[i-1] - 3);
				a1 = (a1*mul.m[1][0] + a2*mul.m[1][1]) * (1-p);
				a2 = a1*p;
			}
		}
		printf("%.7f\n", a1);
	}
	return 0;
}
