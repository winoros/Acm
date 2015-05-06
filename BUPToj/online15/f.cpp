/*===============================================================
*   
*   FILE NAME:  f.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       04/11/2015 13:25:39
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
#include <bits/stdc++.h>

static inline int getIdx(int l, int r) {
	return (l+r) | (l!=r);
}

long long sqrSum[100010<<1], sum[100010<<1];

static inline void pushUp(int l, int r) {
	int m = (l+r)>>1;
	int idx = getIdx(l, r), lidx = getIdx(l, m), ridx = getIdx(m+1, r);
	sum[idx] = sum[lidx] + sum[ridx];
	sqrSum[idx] = sqrSum[lidx] + sqrSum[ridx];
}

void build(int l, int r) {
	int idx = getIdx(l, r);
	if(l == r) {
		scanf("%lld", &sum[idx]);
		sqrSum[idx] = sum[idx] * sum[idx];
		return ;
	}
	int m = (l+r)>>1;
	build(l, m);
	build(m+1, r);
	pushUp(l, r);
}

void update(int pos, int val, int l, int r) {
	int idx = getIdx(l, r);
	if(l == pos && pos == r) {
		sum[idx] = val;
		sqrSum[idx] = sum[idx] * sum[idx];
		return ;
	}
	int m = (l+r)>>1;
	if(pos <= m)
		update(pos, val, l, m);
	else
		update(pos, val, m+1, r);
	pushUp(l, r);
}

static inline std::pair<long long, long long> add(std::pair<long long, long long> a, std::pair<long long, long long> b) {
	std::pair<long long, long long> ret;
	ret.first = a.first + b.first;
	ret.second = a.second + b.second;
	return ret;
}

std::pair<long long, long long> query(int _l, int _r, int l, int r) {
	int idx = getIdx(l, r);
	if(_l <= l && r <= _r) {
		return std::make_pair(sum[idx], sqrSum[idx]);
	}
	std::pair<long long, long long> ret(0, 0);
	int m = (l+r)>>1;
	if(_l <= m)
		ret = add(ret, query(_l, _r, l, m));
	if(m < _r)
		ret = add(ret, query(_l, _r, m+1, r));
	return ret;
}

void MAIN() {
	int n;
	scanf("%d", &n);
	build(1, n);
	int m;
	scanf("%d", &m);
	for(int i = 0, op, x, y; i < m; ++i) {
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1)
			update(x, y, 1, n);
		else {
			std::pair<long long, long long> ret = query(x, y, 1, n);
			printf("%lld\n", ret.second * (y-x+1) - ret.first*ret.first);
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
