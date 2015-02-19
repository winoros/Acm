/*
 * =====================================================================================
 *
 *       Filename:  5818.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/17 13:33:44
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

void MAIN() {
	int n, m;
	cin >> n >> m;
	vector<int> val(n);
	for(int i = 0; i < n; ++i)
		cin >> val[i];
	vector<int> e[110];
	for(int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		e[u].push_back(v);
	}
	bool used[110] = { false };
	used[0] = true;
	int now = 0, ans = val[0];
	while(true) {
		int next = -1, next_val = -1;
		for(int i = 0; i < e[now].size(); ++i)
			if(next_val < val[e[now][i]] && !used[e[now][i]])
				next = e[now][i], next_val = val[e[now][i]];
		if(next == -1)
			break;
		used[next] = true;
		ans += next_val;
		now = next;
	}
	printf("%d %d\n", ans, now);
}

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cout << "Case " << i << " ";
		MAIN();
	}
	return 0;
}
