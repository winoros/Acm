/*
 * =====================================================================================
 *
 *       Filename:  2492.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/23 15:30:36
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

int p[2010<<1];

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

void merge(int x, int y) {
	int px = find(x), py = find(y);
	p[px] = py;
}

void init(int n) {
	n<<=1;
	for(int i = 1; i <= n; ++i)
		p[i] = i;
}

void MAIN() {
	int n, m;
	scanf("%d%d", &n, &m);
	init(n);
	bool need_judge = true;
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(need_judge) {
			int pa = find(a), pb = find(b);
			if(pa == pb) {
				puts("Suspicious bugs found!\n");
				need_judge = false;
			}
			merge(a, b+n), merge(a+n, b);
		}
	}
	if(need_judge)
		puts("No suspicious bugs found!\n");
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		printf("Scenario #%d:\n", i);
		MAIN();
	}
	return 0;
}

