/*
 * =====================================================================================
 *
 *       Filename:  1032.cpp
 *
 *    Description:  solve the 1032th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/26 3:41:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>

int used[10000];
int a[10001];

int main() {
	int n, mod;
	scanf("%d", &n);
	mod = 0, used[0] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		mod = (mod+a[i])%n;
		if(!mod) {
			printf("%d\n", i);
			for(int j = 1; j <= i; j++)
				printf("%d\n", a[j]);
			return 0;
		} else if(used[mod]) {
			printf("%d\n", i - used[mod]);
			for(int j = used[mod]+1; j <= i; j++)
				printf("%d\n", a[j]);
			return 0;
		} else 
			used[mod] = i;
	}
	puts("0");
	return 0;	
}
