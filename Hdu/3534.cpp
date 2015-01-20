/*
 * =====================================================================================
 *
 *       Filename:  4123.cpp
 *
 *    Description
 *
 *        Version:  1.0
 *        Created:  2014/9/21 22:33:56
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

int tail[10010], to[10010<<1], pre[10010<<1], cost[10010<<1], tot;

inline void add(int _from, int _to, int _cost) {
	pre[tot] = tail[_from];
	to[tot] = _to;
	cost[tot] = _cost;
	tail[_from] = tot++;
}

int first[10010], first_cnt[10010], second[10010], second_cnt[10010];
int dia[10010], cnt[10010];

void dfs(int now, int fa) {
	first[now] = first_cnt[now] = second[now] = second_cnt[now] = 0;
	dia[now] = cnt[now] = 0;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		int _to = to[i], _cost = cost[i];
		if(_to == fa)
			continue;
		dfs(_to, now);
		if(first[now] < first[_to] + _cost) {
			second[now] = first[now];
			second_cnt[now] = first_cnt[now];
			first[now] = first[_to] + _cost;
			first_cnt[now] = first_cnt[_to];
			if(!second_cnt[now])
				dia[now] = first[now], cnt[now] = first_cnt[now];
			else 
				dia[now] = first[now] + second[now], cnt[now] = first_cnt[now]*second_cnt[now];
		} else if(first[now] == first[_to] + _cost) {
			if((dia[now]>>1) == first[now])
				cnt[now] += first_cnt[now] * first_cnt[_to];
			else
				cnt[now] = first_cnt[now] * first_cnt[_to], dia[now] = first[now]<<1;
			first_cnt[now] += first_cnt[_to];
		} else if(second[now] < first[_to] + _cost) {
			second[now] = first[_to] + _cost;
			second_cnt[now] = first_cnt[_to];
			if((dia[now]>>1) != first[now])
				dia[now] = first[now] + second[now], cnt[now] = first_cnt[now]*second_cnt[now];
		} else if(second[now] == first[_to] + _cost) {
			second_cnt[now] += first_cnt[_to];
			if((dia[now]>>1) != first[now])
				cnt[now] = first_cnt[now]*second_cnt[now];
		}
	}
	if(!first_cnt[now])
		first_cnt[now] = cnt[now] = 1;
}

int main() {
	int n;
	while(scanf("%d", &n) > 0) {
		tot = 0;
		memset(tail, -1, sizeof tail);
		for(int i = 1; i < n; i++) {
			int _u, _v, _cost;
			scanf("%d%d%d", &_u, &_v, &_cost);
			add(_u, _v, _cost);
			add(_v, _u, _cost);
		}
		dfs(1, -1);
		int maxx = 0, ans = 0;
		for(int i = 1; i <= n; i++) {
			if(maxx < dia[i])
				maxx = dia[i], ans = cnt[i];
			else if(maxx == dia[i])
				ans += cnt[i];
		}
		printf("%d %d\n", maxx, ans);
	}
	return 0;
}
