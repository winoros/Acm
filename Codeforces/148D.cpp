/*
 * =====================================================================================
 *
 *       Filename:  148D.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/22 20:21:09
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

double dp[1010][1010] = { 0 }; //white, black

double dfs(int w, int b) {
	if(!w)
		return 0;
	if(!b)
		return 1;
	double &ret = dp[w][b];
	if(ret != -1)
		return ret;
	ret = 0;
	ret += (double) w/(w+b);
	if(b >= 3)
		ret += ((double)b/(w+b)) * ((double)(b-1)/(w+b-1)) * ((double)(b-2)/(w+b-2)) * dfs(w, b-3);
	if(b >= 2 && w >= 1)
		ret += ((double)b/(w+b)) * ((double)(b-1)/(w+b-1)) * ((double)w/(w+b-2))*dfs(w-1, b-2);
	return ret;
}

int main() {
	int w, b;
	scanf("%d%d", &w, &b);
	for(int i = 0; i <= w; ++i)
		for(int j = 0; j <= b; ++j)
			dp[i][j] = -1;
	printf("%.17f\n", dfs(w, b));
	return 0;
}
