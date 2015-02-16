/*
 * =====================================================================================
 *
 *       Filename:  b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/16 14:46:31
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

inline int sq(int x) {
	return x*x;
}

pair<int, int> p[510];
bool update(double &now, double cmp) {
	if(now < cmp) {
		now = cmp;
		return true;
	}
	else 
		return false;
}

void MAIN() {
	int n;
	scanf("%d" ,&n);
	for(int i = 0; i < n; ++i)
		scanf("%d%d", &p[i].first, &p[i].second);
	double ans = -1;
	int idxi, idxj;
	for(int i = 0; i < n; ++i)
		for(int j = i+1; j < n; ++j)
			if(update(ans, sqrt(sq(p[i].first-p[j].first)*1.0 + sq(p[i].second-p[j].second)*1.0)))
				idxi = i, idxj = j;
	printf("%d %d\n", idxi+1, idxj+1);
}

int main() {
	MAIN();
	return 0;
}
