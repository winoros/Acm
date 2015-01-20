/*
 * =====================================================================================
 *
 *       Filename:  1020.cpp
 *
 *    Description:  solve the 1020th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/22 2:52:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>

using namespace std;

double p[101][2];

double dis(int i, int j) {
	return sqrt((p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1] - p[j][1])*(p[i][1]-p[j][1]));
}

const double pi = acos(-1.0);

int main() {
	int n;
	double r;
	scanf("%d%lf", &n, &r);
	for(int i = 0; i < n; i++)
		scanf("%lf%lf", &p[i][0], &p[i][1]);
	double ans = dis(0, n-1);
	for(int i = 1; i < n; i++)
		ans += dis(i-1, i);
	ans += 2*pi*r;
	printf("%.2f\n", ans);
	return 0;
}
