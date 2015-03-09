/*
 * =====================================================================================
 *
 *       Filename:  100624j.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/3/7 14:26:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

int location[100010], ind[100010];
std::vector<int> v[100010];

int get(int now, int n) {
	std::queue<int> q[2];
	memset(ind, 0, sizeof(int)*n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < v[i].size(); ++j)
			++ind[v[i][j]];
	for(int i = 0; i < n; ++i)
		if(ind[i] == 0)
			q[location[i]].push(i);
	int ret = 0;
	while(!q[0].empty() || !q[1].empty()) {
		if(q[now].empty()) {
			now = 1-now;
			++ret;
			continue;
		}
		int front = q[now].front();
		q[now].pop();
		for(int i = 0; i < v[front].size(); ++i) {
			--ind[v[front][i]];
			if(ind[v[front][i]] == 0)
				q[location[v[front][i]]].push(v[front][i]);
		}
	}
	return ret;
}

void MAIN() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0, tmp; i < n; ++i) {
		scanf("%d", &tmp);
		location[i] = tmp-1;
	}
	for(int i = 0, u, uu; i < m; ++i) {
		scanf("%d%d", &u, &uu);
		--u, --uu;
		v[u].push_back(uu);
	}
	printf("%d\n", std::min(get(0, n), get(1, n)));
	for(int i = 0; i < n; ++i) {
		std::vector<int> tmp;
		v[i].swap(tmp);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--)
		MAIN();
	return 0;
}
