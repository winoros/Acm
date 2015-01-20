/*
 * =====================================================================================
 *
 *       Filename:  1078.cpp
 *
 *    Description:  solve the 1078th problem of Ural  
 *
 *        Version:  1.0
 *        Created:  2014/8/28 18:36:07
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

int dp[510];
int pre[510];

struct node {
	int b, e, idx;
	friend bool operator < (node a, node b) {
		return a.b > b.b;
	}
};

node seg[510];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d%d", &seg[i].b, &seg[i].e);
	for(int i = 0; i < n; i++)
		seg[i].idx = i;
	sort(seg, seg+n);
	memset(pre, -1, sizeof pre);
	for(int i = 0; i < n; i++) {
		dp[i] = 1;
		for(int j = 0; j < i; j++)
			if(seg[j].e < seg[i].e && seg[j].b != seg[i].b && dp[i] < dp[j] + 1)
				dp[i] = dp[j]+1, pre[i] = j;
	}
	int maxx = 1, last = 0;
	for(int i = 0; i < n; i++)
		if(maxx < dp[i])
			maxx = dp[i], last = i;
	printf("%d\n", maxx);
	stack<int> ans;
	ans.push(seg[last].idx);
	while(pre[last] != -1)
		ans.push(seg[pre[last]].idx), last = pre[last];
	while(1) {
		printf("%d", ans.top() + 1); ans.pop();
		if(ans.empty()) {
			putchar('\n');
			break;
		} else 
			putchar(' ');
	}
	return 0;
}
