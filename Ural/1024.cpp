/*
 * =====================================================================================
 *
 *       Filename:  1024.cpp
 *
 *    Description:  solve the 1024th problem of Ural  
 *
 *        Version:  1.0
 *        Created:  2014/8/25 20:09:23
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

int change[1001];

int find_loop(int n) {
	int now = change[n], cnt = 1;
	while(now != n) {
		now = change[now];
		cnt++;
	}
	return cnt;
}

int gcd(int a, int b) {
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int lcm(int a, int b) {
	return a/gcd(a, b) * b;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &change[i]);
	int ans = 1;
	for(int i = 1; i <= n; i++) 
		ans = lcm(ans, find_loop(i));
	printf("%d\n", ans);
	return 0;
}
