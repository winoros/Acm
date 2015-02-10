/*
 * =====================================================================================
 *
 *       Filename:  b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/10 12:08:58
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

int cc;
int p[100010];

void init(int n) {
	cc = n;
	for(int i = 1; i <= n; ++i)
		p[i] = i;
}

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

void merge(int x, int y) {
	int px = find(x), py = find(y);
	if(px == py)
		return ;
	--cc;
	p[px] = py;
}

void MAIN() {
	int n, m;
	scanf("%d%d", &n, &m);
	init(n);
	while(m--) {
		int x, y;
		scanf("%d%d" ,&x, &y);
		merge(x, y);
	}
	printf("%d\n", cc-1);
}

int main() {
	MAIN();
	return 0;
}
