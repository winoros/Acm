/*
 * =====================================================================================
 *
 *       Filename:  1049.cpp
 *
 *    Description:  solve the 1049th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/25 20:30:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>

using namespace std;

int prime[10000], len = 0, cnt[10000];
bool used[20001];

void make_prime() {
	for(int i = 2; i <= 20000; i++) {
		if(used[i]) continue;
		for(int j = i*i; j <= 20000; j+=i)
			used[j] = true;
	}
	for(int i = 2; i <= 20000; i++)
		if(!used[i])
			prime[len++] = i;
}

int main() {
	make_prime();
	int tmp;
	for(int i = 0; i < 10; i++) {
		scanf("%d", &tmp);
		for(int i = 0; prime[i] <= tmp; i++)
			while(!(tmp%prime[i]))
				cnt[i]++, tmp/=prime[i];
	}
	int ans = 1;
	for(int i = 0; i < len; i++)
		ans *= cnt[i] + 1;
	printf("%d\n", ans%10);
	return 0;
}
