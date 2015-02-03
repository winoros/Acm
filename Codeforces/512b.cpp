/*
 * =====================================================================================
 *
 *       Filename:  512b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/3 11:53:55
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

int val[310], cost[310];

void MAIN() {
	vector<pair<int, int> > cur, tmp;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &val[i]);
	for(int i = 0; i < n; ++i)
		scanf("%d", &cost[i]);
	for(int i = 0; i < n; ++i) {
		cur.clear();
		cur = tmp;
		cur.push_back(make_pair(val[i], cost[i]));
		for(vector<pair<int, int> >::iterator iter = tmp.begin(); iter != tmp.end(); ++iter)
			cur.push_back(make_pair(__gcd(val[i], iter->first), cost[i] + iter->second));
		sort(cur.begin(), cur.end());
		int cnt = 1;
		for(int i = 1; i < cur.size(); ++i) {
			if(cur[i].first != cur[cnt-1].first)
				cur[cnt++] = cur[i];
		}
		cur.resize(cnt);
		tmp = cur;
	}
	printf("%d\n", cur[0].first == 1 ? cur[0].second : -1);
}

int main() {
	MAIN();
	return 0;
}
