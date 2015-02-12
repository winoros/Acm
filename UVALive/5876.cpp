/*
 * =====================================================================================
 *
 *       Filename:  5876.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/12 13:05:49
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

unsigned long long hash1[50010], hash2[50010], mul[50010];
char str[50010], strr[50010];

void MAIN() {
	scanf("%s%s", str, strr);
	int len = strlen(str), lenn = strlen(strr);
	hash1[0] = 0, hash2[0] = 0;
	for(int i = 1; i <= len; ++i)
		hash1[i] = hash1[i-1] + (str[i-1]-'a')*mul[i-1];
	for(int i = 1; i <= lenn; ++i)
		hash2[i] = hash2[i-1] + (strr[i-1]-'a')*mul[i-1];
	int minn = min(len, lenn), cnt = 0;
	for(int i = 0; i < minn; ++i)
		if(hash1[len] - hash1[len-i-1] == (hash2[i+1]-hash2[0])*mul[len-i-1])
			++cnt;
	printf("%d\n", cnt+1);
}

int main() {
	mul[0] = 1;
	for(int i = 1; i <= 50000; ++i)
		mul[i] = mul[i-1]*31;
	int n;
	scanf("%d", &n);
	while(n--)
		MAIN();
	return 0;
}
