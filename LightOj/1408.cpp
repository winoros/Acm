/*
 * =====================================================================================
 *
 *       Filename:  1408.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/11/15 23:27:25
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

int main() {
	int nn;
	scanf("%d", &nn);
	for(int ii = 1; ii <= nn; ++ii) {
		double p, q;
		int n, m;
		scanf("%lf%d%d", &p, &n, &m);
		q = 1-p;
		printf("Case %d: ", ii);
		if(p < 1e-9)
			printf("%.10f\n", n*1.0);
		else if(q < 1e-9)
			printf("%.10f\n", m*1.0);
		else {
			double pp = 1-pow(p, m-1), qq = 1-pow(q, n-1);
			double g = (pp*qq/q + qq/p) / (1-pp*qq);
			double f = (qq*pp/p + pp/q) / (1-pp*qq);
			printf("%.10f\n", q*g+p*f+1);
		}
	}
	return 0;
}
