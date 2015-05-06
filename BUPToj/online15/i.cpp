/*
 * =====================================================================================
 *
 *       Filename:  i.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/4/11 14:44:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

int dp[210][60][2];
std::vector<std::pair<int, int> > special, normal;

bool getSpecial(int v, int vv) {
	int sz = special.size();
	memset(dp, -1, sizeof dp);
	dp[0][0][0] = 0;
	int pre = 0, tot = 0;
	for(int i = 0; i < sz; ++i) {
		pre = tot;
		tot += special[i].second;
		for(int w = v; w >= 0; --w) {
			for(int ww = vv; ww >= 0; --ww) {
				if(dp[w][ww][1] == pre) {
					if(w + special[i].first <= v)
						dp[w+special[i].first][ww][1] = tot;
					if(ww + special[i].first <= vv)
						dp[w][ww+special[i].first][1] = tot;
				}
				if(dp[w][ww][0] == pre) {
					if(w+special[i].first <= v)
						dp[w+special[i].first][ww][0] = tot;
					if(ww+special[i].first <= vv)
						dp[w][ww+special[i].first][0] = tot;
					dp[w][ww][1] = tot;
				}
			}
		}
	}
	bool flag = false;
	for(int i = 0; i <= v; ++i)
		for(int j = 0; j <= vv; ++j)
			for(int k = 0; k <= 1; ++k) {
				if(dp[i][j][k] == tot)
					flag = true;
				else
					dp[i][j][k] = -1;
			}
	return flag;
}

int getNormal(int v, int vv) {
	int sz = normal.size();
	for(int i = 0; i < sz; ++i) {
		for(int w = v; w >= 0; --w)
			for(int ww = vv; ww >= 0; --ww) {
				for(int k = 0; k <= 1; ++k) {
					if(dp[w][ww][k] != -1) {
						if(w + normal[i].first <= v)
							dp[w+normal[i].first][ww][k] = std::max(dp[w+normal[i].first][ww][k], dp[w][ww][k] + normal[i].second);
						if(ww + normal[i].first <= vv)
							dp[w][ww+normal[i].first][k] = std::max(dp[w][ww+normal[i].first][k], dp[w][ww][k] + normal[i].second);
					}
				}
				if(dp[w][ww][0] != -1)
					dp[w][ww][1] = std::max(dp[w][ww][1], dp[w][ww][0] + normal[i].second);
			}
	}
	int ans = 0;
	for(int i = 0; i <= v; ++i)
		for(int j = 0; j <= vv; ++j)
			for(int k = 0; k < 2; ++k)
				ans = std::max(ans, dp[i][j][k]);
	return ans;
}

void MAIN(int v, int vv, int n) {
	special.clear();
	normal.clear();
	for(int i = 0, weight, value, op; i < n; ++i) {
		scanf("%d%d%d", &weight, &value, &op);
		if(op == 1)
			special.push_back(std::make_pair(weight, value));
		else
			normal.push_back(std::make_pair(weight, value));
	}
	if(!getSpecial(v, vv))
		puts("-1");
	else
		printf("%d\n", getNormal(v, vv));
	puts("");
}

int main() {
	int v, vv, n, cnt = 0;
	while(scanf("%d%d%d", &v, &vv, &n) == 3) {
		printf("Case %d: ", ++cnt);
		MAIN(v, vv, n);
	}
	return 0;
}
