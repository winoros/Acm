/*
 * =====================================================================================
 *
 *       Filename:  4123.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/9/21 23:41:27
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

int tail[50010], to[50010<<1], pre[50010<<1], cost[50010<<1], tot;

inline void add(int _from, int _to, int _cost) {
	pre[tot] = tail[_from];
	to[tot] = _to;
	cost[tot] = _cost;
	tail[_from]  = tot++;
}

int first[50010], first_id[50010], second[50010];

void dfs1(int now, int fa) {
	first[now] = second[now] = 0;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		int _to = to[i], _cost = cost[i];
		if(_to == fa)
			continue;
		dfs1(_to, now);
		if(second[now] < first[_to] + _cost) {
			second[now] = first[_to] + _cost;
			if(second[now] > first[now]) {
				swap(first[now], second[now]);
				first_id[now] = _to;
			}
		}
	}
}

void dfs2(int now, int fa) {
	for(int i = tail[now]; i != -1; i = pre[i]) {
		int _to = to[i], _cost = cost[i];
		if(_to == fa)
			continue;
		if(first_id[now] != _to) {
			if(second[_to] < first[now] + _cost) {
				second[_to] = first[now] + _cost;
				if(second[_to] > first[_to]) {
					swap(first[_to], second[_to]);
					first_id[_to] = now;
				}
			}
		} else {
			if(second[_to] < second[now] + _cost) {
				second[_to] = second[now] + _cost;
				if(second[_to] > first[_to]) {
					swap(first[_to], second[_to]);
					first_id[_to] = now;
				}
			}
		}
		dfs2(_to, now);
	}
}

int st_max[50010][18], st_min[50010][18];
int log_pre[50010];

void make_st(int n) {
	log_pre[0] = -1;
	for(int i = 1; i <= n; i++) {
		log_pre[i] = log_pre[i-1];
		if((1<<(log_pre[i]+1)) == i)
			log_pre[i]++;
		st_max[i][0] = st_min[i][0] = first[i];
	}
	for(int i = 1; i <= log_pre[n]; i++) {
 		for(int j = 1; j + (1<<i) - 1 <= n; j++) {
			st_max[j][i] = max(st_max[j][i-1], st_max[j+(1<<(i-1))][i-1]);
			st_min[j][i] = min(st_min[j][i-1], st_min[j+(1<<(i-1))][i-1]);
		}
	}
}

inline int st_query(int l, int r) {
	int k =	log_pre[r-l+1];
	return max(st_max[l][k], st_max[r - (1<<k) + 1][k]) - min(st_min[l][k], st_min[r - (1<<k) + 1][k]);
}

int main() {
	int n, m;
	for(scanf("%d%d", &n, &m); n; scanf("%d%d", &n, &m)) {
		tot = 0;
		memset(tail, -1, sizeof tail);
		for(int i = 1; i < n; i++) {
			int _u, _v, _cost;
			scanf("%d%d%d", &_u, &_v, &_cost);
			add(_u, _v, _cost);
			add(_v, _u, _cost);
		}
		dfs1(1, -1);
		dfs2(1, -1);
		make_st(n);
		while(m--) {
			int q;
			scanf("%d",&q);
            int ans = 0, id = 1;
            for(int i = 1;i <= n;i++) {
                while(id <= i && st_query(id,i) > q)id++;
                ans = max(ans,i-id+1);
            }
            printf("%d\n",ans);
		}
	}
	return 0;
}
