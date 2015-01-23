/*
 * =====================================================================================
 *
 *       Filename:  1703.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/23 11:24:33
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

int p[100010<<1];

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
	while(m--) {
		char str[3];
		int a, b;
		scanf("%s%d%d", str, &a, &b);
		if(str[0] == 'A') {
			int pa = find(a), pb = find(b), ppb = find(b+n);
			if(pa == pb)
				puts("In the same gang.");
			else if(pa == ppb)
				puts("In different gang.");
			else
				puts("Not sure yet.");
		} else {
			merge(a, b+n), merge(a+n, b);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--)
		MAIN();
	return 0;
}
