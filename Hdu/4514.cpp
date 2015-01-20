/*===============================================================
*   
*   FILE NAME:  4514.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       09/09/2014 14:57:04
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
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

int tail[100010], pre[2000010], to[2000010], length[2000010], tot;
int p[100010];
int far_node, far_dis;
int used[100010];

inline void add(int _u, int _v, int _length) {
	pre[tot] = tail[_u];
	to[tot] = _v;
	length[tot] = _length;
	tail[_u] = tot++;
}

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

void dfs(int now, int fa, int dis) {
	used[now] = true;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		int _to = to[i], _length = length[i];
		if(_to == fa) continue;
		if(far_dis < dis + _length)
			far_dis = dis + _length, far_node = _to;
		dfs(_to, now, dis + _length);
	}
}

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) > 0) {
		for(int i = 1; i <= n; i++)
			p[i] = i;
		memset(tail, -1, sizeof tail);
		tot = 0;
		bool circle = false;
		while(m--) {
			int u, v, cost;
			scanf("%d%d%d", &u, &v, &cost);
			add(u, v, cost);
			add(v, u, cost);
			int uf = find(u), vf = find(v);
			if(uf == vf)
				circle = true;
			else
				p[uf] = vf;
		}
		if(circle)
			puts("YES");
		else {
			int ans = 0;
			memset(used, 0, sizeof used);
			for(int i = 1; i <= n; i++) {
				if(!used[i]) {
					far_dis = 0;
					dfs(i, -1, 0);
					far_dis = 0;
					dfs(far_node, -1, 0);
					ans = max(far_dis, ans);
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
