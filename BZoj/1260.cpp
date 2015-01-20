/*===============================================================
*   
*   FILE NAME:  1260.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       10/13/2014 18:58:38
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
#include <bits/stdc++.h>

using namespace std;

int dp[110][110];
char str2[110];

int dfs(int l, int r) {
	if(l > r)
		return 0;
	if(l == r)
		return 1;
	int &ret = dp[l][r];
	if(ret != 0x3f3f3f3f)
		return ret;
	for(int m = l; m < r; ++m)
		ret = min(ret, dfs(l, m) + dfs(m+1, r));
	if(str2[l] == str2[r])
		--ret;
	return ret;
}

int ans[110];

int main() {
	while(scanf("%s", str2) > 0) {
		memset(dp, 0x3f, sizeof dp);
		int len = strlen(str2);
		printf("%d\n", dfs(0, len-1));
	}
	return 0;
}
