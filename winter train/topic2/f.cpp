/*
 * =====================================================================================
 *
 *       Filename:  f.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/11 12:04:27
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

struct dsu {
	int p[1010];
	void init(int n) {
		for(int i = 1; i <= n; ++i)
			p[i] = i;
	}
	int find(int x) {
		return p[x] == x ? x : p[x] = find(p[x]);
	}
};

dsu row[1010];
bool used[1010][1010];
int d[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
queue<pair<int, int> > q;
int n;

bool check(int i, int j, int minx, int miny, int maxx, int maxy) {
	return i >= minx && i <= maxx && j >= miny && j <= maxy && !used[i][j];
}

void bfs(int bi, int bj, int minx, int miny, int maxx, int maxy) {
	while(!q.empty())
		q.pop();
	q.push(make_pair(bi, bj));
	used[bi][bj] = true;
	while(!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		if(used[now.first][now.second-1])
			row[now.first].p[now.second-1] = now.second;
		if(used[now.first][now.second+1])
			row[now.first].p[now.second] = now.second+1;
		for(int i = 0; i < 4; ++i)
			if(check(now.first+d[i][0], now.second+d[i][1], minx, miny, maxx, maxy))
				q.push(make_pair(now.first+d[i][0], now.second+d[i][1])),
					used[now.first+d[i][0]][now.second+d[i][1]] = true;
	}
}

void MAIN() {
	int m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		row[i].init(n);
	while(m--) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int ans = 0;
		for(int i = x1; i <= x2; ++i)
			for(int j = y1; j <= y2; j = row[i].find(j)+1)
				if(!used[i][j])
					bfs(i, j, x1, y1, x2, y2), ++ans;
		printf("%d\n", ans);
	}
}

int main() {
	MAIN();
	return 0;
}
