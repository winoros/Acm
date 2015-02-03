/*
 * =====================================================================================
 *
 *       Filename:  512a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/3 12:59:53
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

int ind[27];
string cur, pre;
vector<int> v[27];
int ans[27];
bool used[27];

void MAIN() {
	int n;
	scanf("%d", &n);
	cin >> pre;
	memset(ind, 0, sizeof ind);
	for(int i = 1; i < n; ++i) {
		cin >> cur;
		int j = 0;
		for(; j < cur.size() && j < pre.size() && cur.at(j) == pre.at(j); ++j)
			;
		if(j == pre.size())
			continue;
		else if(j == cur.size()) {
			puts("Impossible");
			return ;
		} else {
			++ind[cur.at(j)-'a'];
			v[pre.at(j)-'a'].push_back(cur.at(j)-'a');
		}
		pre = cur;
	}
	memset(used, 0, sizeof used);
	int anslen = 0;
	while(1) {
		int now;
		for(now = 0; now < 26; ++now)
			if(!used[now] && ind[now] == 0)
				break;
		if(now == 26) {
			break;
			return ;
		} else {
			ans[anslen++] = now;
			used[now] = true;
			for(vector<int>::iterator iter = v[now].begin(); iter != v[now].end(); ++iter)
				--ind[*iter];
		}
	}
	if(anslen < 26)
		puts("Impossible");
	else {
		for(int i = 0; i < 26; ++i)
			printf("%c", ans[i]+'a');
		puts("");
	}
}

int main() {
	MAIN();
	return 0;
}
