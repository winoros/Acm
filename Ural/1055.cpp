/*
 * =====================================================================================
 *
 *       Filename:  1055.cpp
 *
 *    Description:  solve the 1055th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/28 15:18:08
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

int prime[10000], cnt[10000] = { 0 }, len;
bool used[50110] = { false };

void make_prime() {
	int upper = sqrt(50000)+10;
	for(int i = 2; i <= 50000; i++) {
		if(used[i]) continue;
		for(int j = i*i; i <= upper && j <= 50000; j += i)
			used[j] = true;
	}
	len = 0;
	for(int i = 2; i <= 50000; i++)
		if(!used[i])
			prime[len++] = i;
}

int main() {
	make_prime();
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < len && prime[i] <= n; i++) {
		int now = prime[i];
		while(now <= n)
			cnt[i] += n/now, now*=prime[i];
	}
	for(int i = 0; i < len && prime[i] <= m; i++) {
		int now = prime[i];
		while(now <= m)
			cnt[i] -= m/now, now*=prime[i];
	}
	for(int i = 0; i < len && prime[i] <= n-m; i++) {
		int now = prime[i];
		while(now <= n-m)
			cnt[i] -= (n-m)/now, now*=prime[i];
	}
	int ans = 0;
	for(int i = 0; i < len; i++)
		if(cnt[i] > 0) ans++;
	printf("%d\n", ans);
	return 0;
}
