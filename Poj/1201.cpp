/*
 * =====================================================================================
 *
 *       Filename:  1201.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/30 14:29:44
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

int to[50010<<2], cost[50010<<2], pre[50010<<2], tail[50010];
int e_tot;

inline void add(int _from, int _to, int _cost) {
	to[e_tot] = _to;
	cost[e_tot] = _cost;
	pre[e_tot] = tail[_from];
	tail[_from] = e_tot++;
}

int dis[50010];
queue<int> q;

void spfa(int src) {
	while(!q.empty())
		q.pop();
	memset(dis, 0x3f, sizeof dis);
	dis[src] = 0;
	q.push(src);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for(int i = tail[now]; i != -1; i = pre[i]) {
			if(dis[to[i]] > dis[now] + cost[i]) {
				dis[to[i]] = dis[now] + cost[i];
				q.push(to[i]);
			}
		}
	}
}

void MAIN() {
	int n;
	scanf("%d", &n);
	memset(tail, -1 ,sizeof tail);
	e_tot = 0;
	int maxx = 0;
	for(int i = 0, u, v, c; i < n; ++i) {
		scanf("%d%d%d", &u, &v, &c);
		maxx = max(maxx, v);
		add(v, u-1, -c);
	}
	for(int i = 0; i < maxx; ++i) {
		add(i, i+1, 1);
		add(i+1, i, 0);
	}
	spfa(maxx);
	printf("%d\n", dis[0]);
}

int main() {
	MAIN();
	return 0;
}
