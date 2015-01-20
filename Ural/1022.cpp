/*
 * =====================================================================================
 *
 *       Filename:  1022.cpp
 *
 *    Description:  solve the 1022th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/23 21:01:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>

using namespace std;

int ans[110];
vector<int> v[110];
stack<int> s;
int degree[110];
int n;

void topo() {
	int len = 0;
	while(len < n) {
		int top;
		for(int i = 1; i <= n; i++) 
			if(!degree[i]) {
				ans[len++] = i, degree[i]--;
				s.push(i);
			}
		while(!s.empty()) {
			top = s.top(); s.pop();
			int sz = v[top].size();
			for(int i = 0; i < sz; i++)
				if(degree[v[top][i]])
					degree[v[top][i]]--;
		}
	}	
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int tmp;
		while(scanf("%d", &tmp) && tmp)
			v[i].push_back(tmp), degree[tmp]++;
	}
	topo();
	for(int i = 0; i < n; i++)
		printf("%d%c", ans[i], i ==  n-1 ? '\n' : ' ');
	return 0;
}
