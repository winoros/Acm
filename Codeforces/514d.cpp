/*
 * =====================================================================================
 *
 *       Filename:  514d.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/17 0:53:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

using namespace std;

int preLog[100010];
int st_max[100010][5][18];
int data[100010][5];

void make_st(int n, int m) {
	preLog[0] = -1;
	for(int i = 1; i <= n; ++i) {
		preLog[i] = preLog[i-1] + (1<<(preLog[i-1]+1) == i ? 1 : 0);
		for(int j = 0; j < m; ++j)
			st_max[i-1][j][0] = data[i-1][j];
	}
	for(int k = 1; k <= preLog[n]; ++k)
		for(int i = 0; i + (1<<k) - 1 < n; ++i)
			for(int j = 0; j < m; ++j)
				st_max[i][j][k] = max(st_max[i][j][k-1], st_max[i+(1<<(k-1))][j][k-1]);
}

inline int query(int l, int r, int k) {
	int kk = preLog[r-l+1];
	int ret = 0;
	ret += max(st_max[l][k][kk], st_max[r-(1<<kk)+1][k][kk]);
	return ret;
}

void MAIN() {
	int n, m;
    long long target;
	scanf("%d%d%I64d", &n, &m, &target);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d", &data[i][j]);
	make_st(n, m);
	int ans_len = -1, ans[5], tmp[5];
	for(int i = 0, j = 0; i < n; ++i) {
		for(; j < n; ++j) {
			long long sum = 0;
			for(int k = 0; k < m; ++k) {
				tmp[k] = query(i, j, k);
				sum += tmp[k];
			}
			if(sum > target)
				break;
			if(ans_len < j-i+1)
				ans_len = j-i+1, swap(ans, tmp);
		}
	}
	if(ans_len == -1)
		memset(ans, 0, sizeof ans);
	for(int i = 0; i < m; ++i)
		printf("%d%c", ans[i], i == m-1 ? '\n' : ' ');
}

int main() {
	MAIN();
	return 0;
}
