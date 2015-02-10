/*
 * =====================================================================================
 *
 *       Filename:  e.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/10 15:27:41
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

int p[50005*3];

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

void merge(int x, int y) {
	p[find(x)] = find(y);
}


void MAIN() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n*3; ++i)
		p[i] = i;
	int ans = 0;
	while(m--) {
		int op, x, y;
		scanf("%d%d%d" ,&op, &x, &y);
		if(x > n || y > n)
			++ans;
		else {
			int px = find(x), pxx = find(x+n), pxxx = find(x+2*n);
			int py = find(y), pyy = find(y+n), pyyy = find(y+2*n);
			if(op == 1) {
				if(px == pyy || px == pyyy)
					++ans;
				else
					merge(px, py), merge(pxx, pyy), merge(pxxx, pyyy);
			} else {
				if(px == py || px == pyyy)
					++ans;
				else merge(px, pyy), merge(pxx, pyyy), merge(pxxx, py);
			}
		}
	}
	printf("%d\n", ans);
}

int main() {
	MAIN();
	return 0;
}
