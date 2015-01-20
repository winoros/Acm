/*
 * =====================================================================================
 *
 *       Filename:  1364.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/11/16 15:49:33
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

double dp[14][14][14][14][5][5];
int c, d, h, s;

double dfs(int i, int j, int k, int l, int joker, int jokerr) {
	double &ret = dp[i][j][k][l][joker][jokerr];
	if(ret > -0.5)
		return ret;
	ret = 0;
	int now[5];
	now[1] = i, now[2] = j, now[3] = k, now[4] = l;
	++now[joker], ++now[jokerr];
	int left = 54 - now[1] - now[2] - now[3] - now[4];
	if(now[1] >= c && now[2] >= d && now[3] >= h && now[4] >= s)
		return 0;
	if(i < 13)
		ret += (13-i)*1.0/left * dfs(i+1, j, k, l, joker, jokerr);
	if(j < 13)
		ret += (13-j)*1.0/left * dfs(i, j+1, k, l, joker, jokerr);
	if(k < 13)
		ret += (13-k)*1.0/left * dfs(i, j, k+1, l, joker, jokerr);
	if(l < 13)
		ret += (13-l)*1.0/left * dfs(i, j, k, l+1, joker, jokerr);
	if(!joker) {
		double minn = 100;
		for(int chosen = 1; chosen < 5; ++chosen)
			minn = min(minn, dfs(i, j, k, l, chosen, jokerr));
		ret += 1.0/left * minn;
	}
	if(!jokerr) {
		double minn = 100;
		for(int chosen = 1; chosen < 5; ++chosen)
			minn = min(minn, dfs(i, j, k, l, joker, chosen));
		ret += 1.0/left * minn;
	}
	return ret += 1;
}

int main() {
	int nn;
	scanf("%d", &nn);
	for(int ii = 1; ii <= nn; ++ii) {
		scanf("%d%d%d%d", &c, &d, &h, &s);
		int need = 0;
		need -= 13-c < 0 ? 13-c : 0;
		need -= 13-d < 0 ? 13-d : 0;
		need -= 13-h < 0 ? 13-h : 0;
		need -= 13-s < 0 ? 13-s : 0;
		printf("Case %d: ", ii);
		if(need > 2)
			puts("-1");
		else {
			memset(dp, -1, sizeof dp);
			printf("%.11f\n", dfs(0, 0, 0, 0, 0, 0));
		}
	}
	return 0;
}
