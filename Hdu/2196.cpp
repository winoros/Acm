/*
 * =====================================================================================
 *
 *       Filename:  2196.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/9/12 21:21:46
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

int ans[10010];
int tail[10010], pre[10010], to[10010], cost[10010], tot;
int first[10010], first_id[10010], second[10010];

inline void add(int _from, int _to, int _cost) {
	pre[tot] = tail[_from];
	to[tot] = _to;
	cost[tot] = _cost;
	tail[_from] = tot++;
}

void dfs1(int now) {
	first[now] = second[now] = 0;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		int _to = to[i], _cost = cost[i];
		dfs1(_to);
		if(first[now] < first[_to] + _cost) {
			second[now] = first[now];
			first[now] = first[_to] + _cost;
			first_id[now] = _to;
		} else if(second[now] < first[_to] + _cost) {
			second[now] = first[_to] + _cost;
		}
	}
}

void dfs2(int now) {
	for(int i = tail[now]; i != -1; i = pre[i]) {
		int _to = to[i], _cost = cost[i];
		if(first_id[now] != _to) {
			if(first[_to] < first[now] + _cost) {
				second[_to] = first[_to];
				first[_to] = first[now] + _cost;
				first_id[_to] = now;
			} else if(second[_to] < first[now] + _cost) {
				second[_to] = first[now] + _cost;
			}
		} else {
			if(first[_to] < second[now] + _cost) {
				second[_to] = first[_to];
				first[_to] = second[now] + _cost;
				first_id[_to] = now;
			} else if(second[_to] < second[now] + _cost) {
				second[_to] = second[now] + _cost;
			}
		}
		dfs2(_to);
	}
}

int main() {
	int n;
	while(scanf("%d", &n) > 0) {
		memset(tail, -1, sizeof tail);
		tot = 0;
		for(int i = 2; i <= n; i++) {
			int _from, _cost;
			scanf("%d%d", &_from, &_cost);
			add(_from, i, _cost);
		}
		dfs1(1);
		dfs2(1);
		for(int i = 1; i <= n; i++)
			printf("%d\n", first[i]);
	}
	return 0;
}
