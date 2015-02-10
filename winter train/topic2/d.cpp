/*
 * =====================================================================================
 *
 *       Filename:  d.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/10 14:59:01
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

struct goods {
	int val, dl;
};

goods g[100010];

bool cmp(const goods &lhs, const goods &rhs) {
	return lhs.dl > rhs.dl;
}

void MAIN(int n) {
	int longest = -1;
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &g[i].val, &g[i].dl);
		longest = max(longest, g[i].dl);
	}
	priority_queue<int> q;
	int pt = 0, ans = 0;
	sort(g, g+n, cmp);
	for(int now = longest; now > 0; --now) {
		while(pt < n && g[pt].dl == now)
			q.push(g[pt++].val);
		if(!q.empty()) {
			ans += q.top();
			q.pop();
		}
	}
	printf("%d\n", ans);
}

int main() {
	int n;
	while(scanf("%d", &n) > 0)
		MAIN(n);
	return 0;
}
