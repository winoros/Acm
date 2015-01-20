/*===============================================================
*   
*   FILE NAME:  1230.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       09/25/2014 20:28:27
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
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

int tail[1010], to[1010<<1], pre[1010<<1], tot;

inline void add(int _from, int _to) {
	pre[tot] = tail[_from];
	to[tot] = _to;
	tail[_from] = tot++;
}

int dp[1010][2], cnt[1010][2];

void dfs(int now, int fa) {
	dp[now][0] = cnt[now][0] = cnt[now][1] = 0;
	dp[now][1] = 1;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		int _to = to[i];
		if(_to == fa)
			continue;
		dfs(_to, now);
		dp[now][0] += dp[_to][1];
		cnt[now][0] += cnt[_to][1];
		if(dp[_to][0] < dp[_to][1] || (dp[_to][0] == dp[_to][1] && cnt[_to][0] > cnt[_to][1]+1)){
			dp[now][1] += dp[_to][0];
			cnt[now][1] += cnt[_to][0];
		} else {
			dp[now][1] += dp[_to][1];
			cnt[now][1] += cnt[_to][1] + 1;
		}
	}
}

int main() {
	int nn;
	scanf("%d", &nn);
	for(int ii = 1; ii <= nn; ii++) {
		int n, m;
		scanf("%d%d", &n, &m);
		tot = 0;
		memset(tail, -1, sizeof tail);
		for(int i = 0; i < m; i++) {
			int _u, _v;
			scanf("%d%d", &_u, &_v);
			add(_u, _v);
			add(_v, _u);
		}
		memset(dp, -1, sizeof dp);
		int ans = 0, anss = 0;
		for(int i = 0; i < n; i++) {
			if(dp[i][0] == -1) {
				dfs(i, -1);
				if(dp[i][0] < dp[i][1] || (dp[i][0] == dp[i][1] && cnt[i][0] > cnt[i][1]))
					ans += dp[i][0], anss += cnt[i][0];
				else
					ans += dp[i][1], anss += cnt[i][1];
			}
		}
		printf("Case %d: %d %d %d\n", ii, ans, anss, m - anss);
	}
	return 0;
}
