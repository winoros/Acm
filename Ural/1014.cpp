/*
 * =====================================================================================
 *
 *       Filename:  1014.cpp
 *
 *    Description:  solve the 1014th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/22 3:05:06
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

int main() {
	int cnt[10] = {0};
	int n;
	scanf("%d", &n);
	if(n == 1) {
		puts("1");
		return 0;
	}
	if(n == 0) {
		puts("10");
		return 0;
	}
	while(n%2 == 0) cnt[2]++, n>>=1;
	while(n%3 == 0) cnt[3]++, n/=3;
	while(n%5 == 0) cnt[5]++, n/=5;
	while(n%7 == 0) cnt[7]++, n/=7;
	if(n > 9) {
		puts("-1");
		return 0;
	}
	while(cnt[3] >= 2) cnt[9]++, cnt[3]-=2;
	while(cnt[2] >= 3) cnt[8]++, cnt[2]-=3;
	while(cnt[3] && cnt[2]) cnt[6]++, cnt[3]--, cnt[2]--;
	while(cnt[2] > 1) cnt[4]++, cnt[2]-=2;
	for(int i = 2; i < 10; i++)
		while(cnt[i]--) putchar('0'+i);
	puts("");
	return 0;
}

