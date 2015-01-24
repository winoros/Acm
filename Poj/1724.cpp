/*
 * =====================================================================================
 *
 *       Filename:  1724.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/24 13:55:47
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

int to[10010], length[10010], cost[10010], pre[10010], tail[110];
int tot;

inline void add(int _from, int _to, int _length, int _cost) {
	to[tot] = _to;
	length[tot] = _length;
	cost[tot] = _cost;
	pre[tot] = tail[_from];
	tail[_from] = tot++;
}

int dis[110][10010];

struct cmp {
	bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		return a.second > b.second;
	}
};
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int> >, cmp> q;

int spfa(int n, int max_cost) {
	memset(dis, 0x3f, sizeof dis);
	dis[0][0] = 0;
	while(!q.empty())
		q.pop();
	q.push(make_pair(make_pair(0, 0), 0));
	while(!q.empty()) {
		pair<pair<int, int>, int> tmp = q.top();
		q.pop();
		int now_pos = tmp.first.first, now_cost = tmp.first.second;
		if(now_pos == n-1) {
			return dis[now_pos][now_cost];
		} else {
			for(int i = tail[now_pos]; i != -1; i = pre[i]) {
				if(now_cost + cost[i] <= max_cost && dis[now_pos][now_cost] + length[i] < dis[to[i]][now_cost+cost[i]]) {
					dis[to[i]][now_cost+cost[i]] = dis[now_pos][now_cost] + length[i];
					q.push(make_pair(make_pair(to[i], now_cost + cost[i]), dis[to[i]][now_cost+cost[i]]));
				}
			}
		}
	}
	return -1;
}

void MAIN() {
	int k, n, r;
	scanf("%d%d%d", &k, &n, &r);
	memset(tail, -1, sizeof tail);
	tot = 0;
	for(int i = 0, u, v, l, c; i < r; ++i) {
		scanf("%d%d%d%d", &u, &v, &l, &c);
		--u, --v;
		add(u, v, l, c);
	}
	printf("%d\n", spfa(n, k));
}

int main() {
	MAIN();
	return 0;
}
