/*
 * =====================================================================================
 *
 *       Filename:  3411.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/23 22:23:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
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

int to[11], pre[11], mark[11], cost1[11], cost2[11], tail[11];
int tot;

inline void add(int _from, int _to, int _mark, int _cost1, int _cost2) {
	to[tot] = _to;
	mark[tot] = _mark;
	cost1[tot] = _cost1;
	cost2[tot] = _cost2;
	pre[tot] = tail[_from];
	tail[_from] = tot++;
}

int dis[1<<10][11];
queue<pair<int, int> > q;

int spfa(int n) {
	int ans = 0x3f3f3f3f;
	memset(dis, 0x3f, sizeof dis);
	dis[1<<0][0] = 0;
	while(!q.empty())
		q.pop();
	q.push(make_pair(1<<0, 0));
	while(!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();
		int s = tmp.first, now = tmp.second;
		if(now == n-1) {
			ans = min(ans, dis[s][now]);
		} else {
			for(int i = tail[now], cost, next_s; i != -1; i = pre[i]) {
				next_s = s | (1<<to[i]);
				if((s>>mark[i] & 1))
					cost = cost1[i];
				else
					cost = cost2[i];
				if(dis[s][now] + cost < dis[next_s][to[i]]) {
					dis[next_s][to[i]] = dis[s][now] + cost;
					q.push(make_pair(next_s, to[i]));
				}
			}
		}
	}
	return ans;
}

void MAIN() {
	int n, m;
	scanf("%d%d", &n, &m);
	memset(tail, -1, sizeof tail);
	tot = 0;
	for(int i = 0, u, v, c, p, r; i < m; ++i) {
		scanf("%d%d%d%d%d", &u, &v, &c, &p, &r);
		--u, --v, --c;
		add(u, v, c, p, r);
	}
	int ans = spfa(n);
	if(ans == 0x3f3f3f3f)
		puts("impossible");
	else 
		printf("%d\n", spfa(n));
}

int main() {
	MAIN();
	return 0;
}
