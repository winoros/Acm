/*
 * =====================================================================================
 *
 *       Filename:  2298.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/17 17:09:25
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

map<pair<int, int>, int> m;
vector<int> v[100010];

int dp[100010];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(a+b < n) {
			if(m.find(make_pair(a+1, n-b)) != m.end()) {
				if(m[make_pair(a+1, n-b)] < n-a-b)
					m[make_pair(a+1, n-b)]++;
			} else {
				v[n-b].push_back(a+1);
				m[make_pair(a+1, n-b)]++;
			}
		}
	}
	dp[0] = 0;
	for(int i = 1; i <= n; ++i) {
		dp[i] =dp[i-1];
		int sz = v[i].size();
		for(int j = 0; j < sz; ++j)
			dp[i] = max(dp[i], dp[v[i][j]-1] + m[make_pair(v[i][j], i)]);
	}
	printf("%d\n", n - dp[n]);
	return 0;
}
