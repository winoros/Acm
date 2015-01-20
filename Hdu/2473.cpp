/*
 * =====================================================================================
 *
 *       Filename:  2473.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/9/19 12:55:48
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

int p[1100001], hashh[100010];
bool used[1100001];

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

int main() {
	int n, m, casee = 1;
	while(scanf("%d%d", &n, &m) && n) {
		for(int i = 0; i < n; i++)
			p[i] = hashh[i] = i;
		memset(used, 0, sizeof(bool)*(n+5));
		char str[2];
		int tail = n, a, b;
		for(int i = 0; i < m; i++) {
			scanf("%s", str);
			if(str[0] == 'M') {
				scanf("%d%d", &a, &b);
				p[find(hashh[a])] = find(hashh[b]);

			} else {
				scanf("%d", &a);
				hashh[a] = tail++;
				p[hashh[a]] = hashh[a];
			}
		}
		memset(used, 0, sizeof(bool)*(tail+1));
		int ans = 0;
		for(int i = 0; i < n; i++) {
			int fa = find(hashh[i]);
			if(!used[fa])
				used[fa] = true, ans++;
		}
		printf("Case #%d: %d\n", casee++, ans);
	}
	return 0;
}
