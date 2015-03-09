/*
 * =====================================================================================
 *
 *       Filename:  516b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/19 19:36:27
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

char atlas[2010][2010];
int d[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
char tag[4] = { '>', '<', 'v', '^' };
int deg[2010][2010];
queue<pair<int, int> > q;

inline bool judge(int i, int j, int n, int m) {
	return i >= 0 && i < n && j >= 0 && j < m && atlas[i][j] == '.';
}

void MAIN() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%s", atlas[i]);
	int tot = 0;
	while(!q.empty())
		q.pop();
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j) {
			deg[i][j] = 0;
			if(atlas[i][j] == '.') {
				++tot;
				for(int k = 0; k < 4; ++k)
					if(judge(i+d[k][0], j+d[k][1], n, m))
						++deg[i][j];
			}
			if(deg[i][j] == 1)
				q.push(make_pair(i, j));
		}
	while(!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		if(atlas[now.first][now.second] != '.')
			continue;
		for(int i = 0; i < 4; ++i)
			if(judge(now.first+d[i][0], now.second+d[i][1], n, m)) {
				atlas[now.first+d[i][0]][now.second+d[i][1]] = tag[i];
				atlas[now.first][now.second] = tag[i^1];
				now.first+=d[i][0], now.second+=d[i][1];
				for(int j = 0; j < 4; ++j)
					if(judge(now.first+d[j][0], now.second+d[j][1], n, m)) {
						if(--deg[now.first+d[j][0]][now.second+d[j][1]] == 1)
							q.push(make_pair(now.first+d[j][0], now.second+d[j][1]));
					}
				break;
			}
		tot -= 2;
	}
	if(tot != 0)
		puts("Not unique");
	else
		for(int i = 0; i < n; ++i)
			puts(atlas[i]);
}

int main() {
	MAIN();
	return 0;
}
