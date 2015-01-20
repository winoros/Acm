/*
 * =====================================================================================
 *
 *       Filename:  4679.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/9/22 16:44:20
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

int tail[100010], pre[100010<<1], to[100010<<1], cost[100010<<1], tot;

inline void add(int _from, int _to, int _cost) {
	pre[tot] = tail[_from];
	to[tot] = _to;
	cost[tot] = _cost;
	tail[_from] = tot++;
}

bool in_d[100010];
int min_cost, min_id; //minimal cost when the impression is the diameter

int pre_to[100010], pre_id[100010];
int max_dis, max_node;

void dfs(int now, int fa, int pre_deep, bool val) {
	if(max_dis < pre_deep + 1) {
		max_node = now;
		max_dis = pre_deep + 1;
	}
	for(int i = tail[now]; i != -1; i = pre[i]) {
		int _to = to[i];
		if(_to == fa || (!val && in_d[_to]))
			continue;
		if(val)
			pre_to[_to] = now, pre_id[_to] = i;
		if(min_cost > cost[i])
			min_cost = cost[i], min_id = i;
		else if(min_cost == cost[i] && min_id > i)
			min_id = i;
		min_cost = min(min_cost, cost[i]);
		dfs(_to, now, pre_deep+1, val);
	}
}

int main() {
	int nn;
	scanf("%d", &nn);
	for(int ii = 1; ii <= nn; ii++) {
		int n;
		scanf("%d", &n);
		tot = 0;
		memset(tail, -1, sizeof(int)*(n+5));
		for(int i = 1; i < n; i++) {
			int _u, _v, _cost;
			scanf("%d%d%d", &_u, &_v, &_cost);
			add(_u, _v, _cost);
			add(_v, _u, _cost);
		}
		dfs(1, -1, max_dis = -1, true);
		pre_to[max_node] = -1;
		dfs(max_node, -1, max_dis = -1, true);
		int diameter = max_dis;
		int now = max_node, deep = 0;
		min_cost = INT_MAX, min_id = tot;
		long long minn = 1LL<<40;
	    int	ans = tot;
		for(in_d[now] = true; pre_to[now] != -1; now = pre_to[now])
			in_d[pre_to[now]] = true;
		now = max_node;
		while(pre_to[now] != -1) {
			int id = pre_id[now];
			dfs(now, -1, max_dis = -1, false);
			int max_tmp = max_dis + deep;
			dfs(pre_to[now], -1, max_dis = -1, false);
			max_tmp = max(max_tmp, max_dis + diameter - deep - 1);
			if(minn > (long long)max_tmp*cost[id])
				minn =(long long)max_tmp*cost[id], ans = id;
			else if(minn == (long long)max_tmp*cost[id] && ans > id)
				ans = id;
			now = pre_to[now];
			deep++;
		}
		if(minn > (long long)diameter*min_cost)
			minn = (long long)diameter*min_cost, ans = min_id;
		else if(minn == (long long)diameter*min_cost && ans > min_id)
			ans = min_id;
		printf("Case #%d: %d\n", ii, (ans>>1)+1);
	}
	return 0;
}
