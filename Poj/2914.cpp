/*
 * =====================================================================================
 *
 *       Filename:  2914.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/21 16:52:59
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

typedef pair<pair<int, int>, int> piii;

bool used[501], combined[501];
int w_sum[501], atlas[501][501];

piii search(int n) {
	piii ret = make_pair(make_pair(-1, -1), -1);
	memset(used, false, sizeof used);
	memset(w_sum, 0, sizeof w_sum);
	for(int i = 0; i < n; ++i) {
		int next, maxx = -1;
		for(int j = 0; j < n; ++j)
			if(!combined[j] && !used[j] && maxx < w_sum[j])
				maxx = w_sum[j], next = j;
		if(next == ret.first.second)
			break;
		ret.first.first = ret.first.second, ret.first.second = next;
		ret.second = maxx;
		used[next] = true;
		for(int j = 0; j < n; ++j)
			if(!combined[j] && !used[j])
				w_sum[j] += atlas[next][j];
	}
	return ret;
}

int min_cut(int n) {
	int ret = 0x3f3f3f3f;
	memset(combined, false, sizeof combined);
	for(int i = 1; i < n; ++i) {
		piii tmp = search(n);
		ret = min(ret, tmp.second);
		combined[tmp.first.second] = true;
		for(int j = 0; j < n; ++j)
			if(!combined[j]) {
				atlas[tmp.first.first][j] += atlas[tmp.first.second][j];
				atlas[j][tmp.first.first] += atlas[j][tmp.first.second];
			}
	}
	return ret;
}

void MAIN(int n, int m) {
	memset(atlas, 0, sizeof atlas);
	for(int i = 0, u, v, cost; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &cost);
		atlas[u][v] += cost;
		atlas[v][u] += cost;
	}
	printf("%d\n", min_cut(n));
}

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) == 2)
		MAIN(n, m);
	return 0;
}
