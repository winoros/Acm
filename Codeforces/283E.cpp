/*
 * =====================================================================================
 *
 *       Filename:  283E.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/28 21:00:58
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

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

int n;
int sum[100010<<2];
int lisan[100010];
bool cover[100010<<2];

void update(int _l, int _r, int l = 1, int r = n+1, int rt = 1) {
	if(_l <= l && r <= _r) {
//		printf("uuuuuu %d %d %d %d\n", l, r, rt, sum[rt]);
		sum[rt] = r-l+1 - sum[rt];
		cover[rt] ^= 1;
		return ;
	}
	int m = (r+l)>>1, len = r-l+1;
	if(cover[rt]) {
		cover[rt<<1] ^= 1, cover[rt<<1|1] ^= 1;
		sum[rt<<1] = len - (len>>1) - sum[rt<<1];
		sum[rt<<1|1] = (len>>1) - sum[rt<<1|1];
		cover[rt] ^= 1;
	}
	if(_l <= m) update(_l, _r, lson);
	if(m < _r) update(_l, _r, rson);
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

int query(int _l, int _r, int l = 1, int r = n+1, int rt = 1) {
//	printf("qqqqqq %d %d %d %d\n", l, r, rt, sum[rt]);
	if(_l <= l && r <= _r)
		return sum[rt];
	int len = r-l+1;
	if(cover[rt]) {
		cover[rt<<1] ^= 1, cover[rt<<1|1] ^= 1;
		sum[rt<<1] = len - (len>>1) - sum[rt<<1];
		sum[rt<<1|1] = (len>>1) - sum[rt<<1|1];
		cover[rt] ^= 1;
	}
	int ret = 0, m = (r+l)>>1;
	if(_l <= m)
		ret += query(_l, _r, lson);
	if(m < _r)
		ret += query(_l, _r, rson);
	return ret;
}

vector<int> v[100010];
int cow[100010], posx[100010], posy[100010];

int main() {
	int m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", &cow[i]);
	sort(cow, cow+n);
	for(int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		posx[i] = lower_bound(cow, cow+n, l) - cow;
		posy[i] = upper_bound(cow, cow+n, r) - cow;
		v[posx[i]].push_back(i), v[posy[i]].push_back(i);
	}
	long long ret = (long long)n*(n-1)*(n-2)/3;
	memset(sum, 0, sizeof sum);
	memset(cover, 0, sizeof cover);
	for(int i = 0; i < n; ++i) {
		for(int j = 0, sz = v[i].size(); j < sz; ++j) {
			if(posx[v[i][j]]+1 <= posy[v[i][j]])
				update(posx[v[i][j]]+1, posy[v[i][j]]);
		//	printf("%d__%d__\n", posx[v[i][j]]+1, posy[v[i][j]]);
		}
	//	printf("xxxxxx %d\n", i+1);
		long long x = 1 <= i ? query(1, i) : 0, y = i+2 <= n ? query(i+2, n) : 0;
	//	printf("%I64d__%I64d\n", x, y);
		long long xx = x + (n-i-1 - y), yy = (i - x) + y;
		ret -= xx*(xx-1)/2;
		ret -= yy*(yy-1)/2;
	}
	printf("%I64d\n", ret/2);
	return 0;
}
