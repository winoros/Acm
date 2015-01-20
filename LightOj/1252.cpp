/*
 * =====================================================================================
 *
 *       Filename:  1252.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/9/25 23:49:04
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

int tail[110], to[110<<1], pre[110<<1], cost[110<<1], tot;

inline void add(int _from, int _to, int _cost) {
	pre[tot] = tail[_from];
	to[tot] = _to;
	cost[tot] = _cost;
	tail[_from] = tot++;
}

void dfs() {
	
}

int main() {
	int nn;
	scanf("%d", &nn);
	for(int ii = 1; ii <= nn; ii++) {
		int n, k;
		scanf("%d%d", &n, &k);
		for(int i = 1; i < n; i++) {
			int _u, _v, _cost;
			scanf("%d%d%d", &_u, &_v, &_cost);
			add(_u, _v, _cost);
			add(_v, _u, _cost);
		}
		
	}
}
