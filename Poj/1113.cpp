/*
 * =====================================================================================
 *
 *       Filename:  1113.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/10 21:17:16
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

const double pi = acos(-1.0);

struct node {
	int x, y;
};

inline int cross(node a, node b, node c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

node pole;

bool cmp(node a, node b) {
	int tmp = cross(pole, b, a);
	if(tmp < 0)
		return true;
	else if(!tmp)
		return a.x < b.x;
	else
		return false;
}

node ans[1010], p[1010];

int Graham(int n) {
	int pole_idx = 0;
	for(int i = 1; i < n; ++i)
		if(p[i].x < p[pole_idx].x || (p[i].x == p[pole_idx].x && p[i].y < p[pole_idx].y))
			pole_idx = i;
	swap(p[0], p[pole_idx]);
	pole.x = p[0].x, pole.y = p[0].y;
	sort(p+1, p+n, cmp);
	int len = 0;
	ans[len++] = p[0];
	ans[len++] = p[1];
	for(int i = 2; i < n; i++) {
		while(len > 1 && cross(p[i], ans[len-1], ans[len-2]) >= 0)
			--len;
		ans[len++] = p[i];
	}
	return len;
}

inline double dis(node a, node b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main() {
	int n, l;
	scanf("%d%d", &n, &l);
	for(int i = 0; i < n; ++i)
		scanf("%d%d", &p[i].x, &p[i].y);
	int len = Graham(n);
	double ret = dis(ans[0], ans[len-1]);
	for(int i = 0; i < len-1; i++)
		ret += dis(ans[i], ans[i+1]);
	printf("%d\n", (int)(ret + 2*pi*l + 0.5));
	return 0;
}
