/*
 * =====================================================================================
 *
 *       Filename:  4059.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015/1/30 19:02:17
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

const int mod = 1e9+7;

int prime[10000], p_len;
bool not_prime[10000];

void make_prime() {
	memset(not_prime, 0, sizeof not_prime);
	p_len = 0;
	for(int i = 2; i < 10000; ++i) {
		if(!not_prime[i]) {
			prime[p_len++] = i;
			for(int j = 2*i; j < 10000; j+=i)
				not_prime[j] = true;
		}
	}
}

long long fast_pow(long long base, int idx) {
	long long ret = 1;
	while(idx) {
		if(idx&1)
			ret = ret*base %mod;
		base = base*base %mod;
		idx>>=1;
	}
	return ret;
}

const int rev_30 = fast_pow(30, mod-2);
int factor[10000], f_len;

long long sum(long long n) {
	long long ret=n;
	ret=(ret*(n+1))%mod;
	ret=(ret*((2*n+1)%mod))%mod;
	ret=(ret*(((3*n*n)%mod+(3*n)%mod-1+mod)%mod))%mod;
	ret=(ret*rev_30)%mod;
	return ret;
}

long long dfs(int idx, long long n) {
	long long ret = 0, tmp;
	for(int i = idx; i < f_len; ++i) {
		tmp = factor[i];
		ret = (ret + sum(n/tmp)*fast_pow(tmp, 4) %mod) %mod;
		ret = (ret - dfs(i+1, n/tmp)*fast_pow(tmp, 4) %mod + mod) %mod;
	}
	return ret;
}

void make_factor(int n) {
	f_len = 0;
	for(int i = 0;  i < p_len && prime[i] <= n; ++i) {
		if(n %prime[i] == 0) {
			factor[f_len++] = prime[i];
			while(n %prime[i] == 0)
				n /= prime[i];
		}
	}
	if(n != 1)
		factor[f_len++] = n;
}

void MAIN() {
	int n;
	scanf("%d", &n);
	make_factor(n);
	printf("%I64d\n", ((sum(n) - dfs(0, n)) %mod + mod) %mod);
}

int main() {
	make_prime();
	int n;
	scanf("%d", &n);
	while(n--)
		MAIN();
	return 0;
}
