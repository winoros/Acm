/*
 * =====================================================================================
 *
 *       Filename:  2752.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/7 0:38:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define msg _l, _r, val

long long sum[3][100010<<2], change[100010<<2];
int n;

inline long long square_sum(int n) {
	return (long long)n*(n+1)*(2*n+1)/6;
}

inline void push_up(int rt) {
	for(int i = 0; i < 3; ++i)
		sum[i][rt] = sum[i][rt<<1] + sum[i][rt<<1|1];
}

inline void push_down(int l, int r, int rt) {
	if(change[rt]) {
		int len = r-l+1, m = (l+r)>>1;
		sum[0][rt<<1|1] += change[rt] * (len>>1);
		sum[0][rt<<1] += change[rt] * (len - (len>>1));
		sum[1][rt<<1|1] += change[rt] * (len>>1) * (m+1+r) / 2;
		sum[1][rt<<1] += change[rt] * (len - (len>>1)) * (l+m) / 2;
		sum[2][rt<<1|1] +=  change[rt] * (square_sum(r) - square_sum(m));
		sum[2][rt<<1] += change[rt] * (square_sum(m) - square_sum(l-1));
		change[rt<<1] += change[rt];
		change[rt<<1|1] += change[rt];
		change[rt] = 0;
	}
}
/*
void build(int l = 1, int r = n, int rt = 1) {
	if(l == r) {
		scanf("%d", &sum[0][rt]);
		sum[1][rt] = l*sum[0][rt];
		sum[2][rt] = l*sum[1][rt];
	}
}
*/
void update(int _l, int _r, int val, int l = 1, int r = n, int rt = 1) {
	if(_l <= l && r <= _r) {
		change[rt] += val;
		sum[0][rt] += (long long)(r-l+1) * val;
		sum[1][rt] += (long long)val * (r-l+1) * (l+r) / 2;
		sum[2][rt] += val * (square_sum(r) - square_sum(l-1));
		return ;
	}
	push_down(l, r, rt);
	int m = (l+r)>>1;
	if(_l <= m) update(msg, lson);
	if(m < _r) update(msg, rson);
	push_up(rt);
}

std::pair<long long, std::pair<long long, long long> > query(int _l, int _r, int l = 1, int r = n, int rt = 1) {
	if(_l <= l && r <= _r)
		return std::make_pair(sum[0][rt], std::make_pair(sum[1][rt], sum[2][rt]));
	push_down(l, r, rt);
	std::pair<long long, std::pair<long long, long long> > ret, tmp;
	int m = (l+r)>>1;
	if(_l <= m) ret = query(_l, _r, lson);
	if(m < _r) {
		tmp = query(_l, _r, rson);
		ret.first += tmp.first;
		ret.second.first += tmp.second.first;
		ret.second.second += tmp.second.second;
	}
	return ret;
}

int main() {
	int m;
	scanf("%d%d", &n, &m);
	--n;
	memset(sum, 0, sizeof sum);
	memset(change, 0, sizeof change);
	char str[10];
	while(m--) {
		int l, r;
		scanf("%s%d%d", str, &l, &r);
		--r;
		if(str[0] == 'C') {
			int val;
			scanf("%d", &val);
			update(l, r, val);
		} else {
			std::pair<long long, std::pair<long long, long long> > now = query(l, r);
			long long ans = (l+r)*now.second.first + (long long)(r-l+1 - (long long)l*r)*now.first - now.second.second;
			long long ans2 = (long long)(r-l+1)*(r-l+2)/2;
			long long gcd = std::__gcd(ans, ans2);
			printf("%lld/%lld\n", ans/gcd, ans2/gcd);
		}
	}
	return 0;
}
