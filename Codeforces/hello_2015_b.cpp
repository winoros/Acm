/*
 * =====================================================================================
 *
 *       Filename:  hello_2015_b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/10 18:01:39
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

typedef pair<long long, int> pii;

int to[100010], cost[100010], color[100010], pre[100010], tail[100010];
int tot;

inline void add(int _from, int _to, int _cost, int _color) {
	to[tot] = _to;
	cost[tot] = _cost;
	color[tot] = _color;
	pre[tot] = tail[_from];
	tail[_from] = tot++;
}

set<pii> s;

long long  dis[2][100010];
int col[2][100010];

void dij(int src) {
	memset(dis, 0x3f, sizeof dis);
	memset(col, -1, sizeof col);
	dis[0][src] = dis[1][src] = 0;
	s.insert(make_pair(0, src));
	while(!s.empty()) {
		pii tmp = *s.begin();
		s.erase(s.begin());
		int now = tmp.second;
		for(int i = tail[now]; i != -1; i = pre[i]) {
			bool changed = true;
			long long tmpp = dis[0][to[i]];
			if(col[0][now] != color[i]) {
				if(dis[0][to[i]] > dis[0][now] + cost[i]) {
					if(col[1][to[i]] != color[i])
						dis[1][to[i]] = dis[0][to[i]], col[1][to[i]] = dis[1][to[i]];
					dis[0][to[i]] = dis[0][now] + cost[i], col[0][to[i]] = color[i];
				}
				else if(col[1][to[i]] != color[i] && dis[1][to[i]] > dis[0][now] + cost[i])
					dis[1][to[i]] = dis[0][now] + cost[i], col[1][to[i]] = color[i];
				else
					changed = false;
			} else {
				if(col[1][now] != -1) {
					if(dis[0][to[i]] > dis[1][now] + cost[i]) {
						if(col[1][to[i]] != color[i])
							dis[1][to[i]] = dis[0][to[i]], col[1][to[i]] = col[0][to[i]];
						dis[0][to[i]] = dis[1][now] + cost[i], col[0][to[i]] = color[i];
					}
					else if(color[i] != col[1][to[i]] && dis[1][to[i]] > dis[1][now] + cost[i])
						dis[1][to[i]] = dis[1][now] + cost[i], col[0][to[i]] = color[i];
					else 
						changed = false;
				}
			}
			if(changed) {
				if(tmpp != 0x3f3f3f3f3f3f3f3f)
					s.erase(s.find(make_pair(tmpp, to[i])));
				s.insert(make_pair(dis[0][to[i]], to[i]));
			}
		}
	}
}

int main() {
	int n, m, c;
	scanf("%d%d%d", &n, &m, &c);
	tot = 0;
	memset(tail, -1, sizeof tail);
	for(int i = 0, u, v, c, cc; i < m; ++i) {
		scanf("%d%d%d%d", &u, &v, &c, &cc);
		add(u, v, c, cc);
	}
	int src, q;
	scanf("%d%d", &src, &q);
	dij(src);
	for(int i = 0, tmp; i < q; ++i) {
		scanf("%d", &tmp);
		printf("%I64d\n", dis[0][tmp] == 0x3f3f3f3f3f3f3f3f ? -1 : dis[0][tmp]);
	}
	return 0;
}
