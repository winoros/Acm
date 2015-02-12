/*
 * =====================================================================================
 *
 *       Filename:  5059.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/12 21:20:05
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

void MAIN() {
	int n;
	scanf("%d", &n);
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		long long tmp;
		scanf("%lld", &tmp);
		while(tmp & 1)
			tmp>>=1;
		ans ^= tmp>>1;
	}
	if(ans)
		puts("YES");
	else
		puts("NO");
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--)
		MAIN();
	return 0;
}
