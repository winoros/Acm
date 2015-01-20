/*
 * =====================================================================================
 *
 *       Filename:  1072.cpp
 *
 *    Description:  solve the 1072th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/31 19:52:28
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

struct node {
	int num[4];
	friend bool operator == (node a, node b) {
		for(int i = 0; i < 4; i++)
			if(a.num[i] != b.num[i])
				return false;
		return true;
	}
};

vector<int> e[91];
vector<node> duankou[91];
int dis[91], pre[91], cnt[91];
queue<int> q;

inline node make_node(int *a) {
	node ret;
	for(int i = 0; i < 4; i++)
		ret.num[i] = a[i];
	return ret;
}

void spfa(int src) {
	memset(dis, 0x3f, sizeof dis);
	memset(pre, -1, sizeof pre);
	dis[src] = 0;
	q.push(src);
	while(!q.empty()) {
		int now = q.front(); q.pop();
		int sz = e[now].size();
		for(int i = 0; i < sz; i++) {
			if(dis[e[now][i]] > dis[now] + 1)
				dis[e[now][i]] = dis[now] + 1, pre[e[now][i]] = now, q.push(e[now][i]);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", cnt+i);
		for(int j = 0; j < cnt[i]; j++) {
			int num[4], tmp[4];
			scanf("%d.%d.%d.%d", num, num+1, num+2, num+3);
			scanf("%d.%d.%d.%d", tmp, tmp+1, tmp+2, tmp+3);
			for(int k = 0; k < 4; k++)
				num[k] &= tmp[k];
			duankou[i].push_back(make_node(num));
			for(int k = 0; k < i; k++) {
				int sz = duankou[k].size();
				for(int l = 0; l < sz; l++)
					if(duankou[k][l] == duankou[i][j])
						e[i].push_back(k), e[k].push_back(i);
			}
		}
	}
	int s, e;
	scanf("%d%d", &s, &e);
	s--, e--;
	spfa(s);
	if(dis[e] >= 0x3f3f3f3f)
		puts("No");
	else {
		puts("Yes");
		stack<int> ans;
		int now = e;
		ans.push(now);
		while(pre[now] != -1)
			ans.push(pre[now]), now = pre[now];
		while(1) {
			printf("%d", ans.top()+1); ans.pop();
			if(ans.empty()) {
				putchar('\n');
				break;
			} else
				putchar(' ');
		}
	}
	return 0;
}
