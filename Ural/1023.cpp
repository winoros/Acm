/*
 * =====================================================================================
 *
 *       Filename:  1023.cpp
 *
 *    Description:  solve the 1023th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/24 21:00:19
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

typedef long long ll;

int main() {
	ll n;
	scanf("%I64d", &n);
	ll ans = n-1;
	if(n > 4 && !(n&1))
		ans = n/2-1;
	for(ll i = 3; i*i <= n; i++) 
		if(n%i == 0) {
			ans = i-1;
			break;
		}
	printf("%I64d\n", ans);
	return 0;
}
