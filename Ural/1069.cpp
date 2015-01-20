/*
 * =====================================================================================
 *
 *       Filename:  1069.cpp
 *
 *    Description:  solve the 1069th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/9/2 3:12:26
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

int deg[7501], a[7501];
priority_queue<int, vector<int>, greater<int> > q;
vector<int> v[7501];

int main() {
	int len = 0;
	while(scanf("%d", &a[len++]) > 0)
		deg[a[len-1]]++;
	for(int i = 1; i <= len; i++)
		if(!deg[i])
			q.push(i);
	for(int i = 0; i < len-1; i++) {
		int top = q.top(); q.pop();
		v[top].push_back(a[i]);
		v[a[i]].push_back(top);
		if(!--deg[a[i]])
			q.push(a[i]);
	}
	for(int i = 1; i <= len; i++) {
		sort(v[i].begin(), v[i].end());
		int sz = v[i].size();
		printf("%d: ", i);
		for(int j = 0; j < sz; j++)
			printf("%d%c", v[i][j], j == sz-1 ? '\n' : ' ');
	}
	return 0;
}
