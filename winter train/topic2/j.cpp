/*
 * =====================================================================================
 *
 *       Filename:  j.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/10 22:33:14
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

int op[100010], record[100010], recordd[100010];
pair<int, int> bridge[100010];
bool ans[100010];
int destroyed[100010];
int p[100010];

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

void merge(int x, int y) {
	p[find(x)] = find(y);
}

void MAIN() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i)
		scanf("%d%d", &bridge[i].first, &bridge[i].second);
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i) {
		char str[2];
		scanf("%s%d", str, &record[i]);
		if(str[0] == 'D') {
			--record[i];
			op[i] = 0;
			++destroyed[record[i]];
		} else {
			op[i] = 1;
			scanf("%d", &recordd[i]);
		}
	}
	for(int i = 1; i <= n; ++i)
		p[i] = i;
	for(int i = 0; i < m; ++i)
		if(destroyed[i] == 0)
			merge(bridge[i].first, bridge[i].second);
	int anslen = 0;
	for(int i = t-1; i >= 0; --i)
		if(op[i] == 1)
			ans[anslen++] = find(record[i]) == find(recordd[i]);
		else if(--destroyed[record[i]] == 0)
				merge(bridge[record[i]].first, bridge[record[i]].second);
	for(int i = anslen-1; i >= 0; --i)
		printf("%d\n", ans[i]);
}

int main() {
	MAIN();
	return 0;
}
