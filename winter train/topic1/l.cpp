/*
 * =====================================================================================
 *
 *       Filename:  l.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/26 16:17:21
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


int a[20];

void MAIN() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);
	for(int i = 0; i < 1000; ++i) {
		int tmp = a[0];
		for(int j = 0; j < n-1; ++j)
			a[j] = abs(a[j] - a[j+1]);
		a[n-1] = abs(tmp - a[n-1]);
	}
	int i;
	for(i = 0; i < n && a[i] == 0; ++i)
		;
	if(i == n)
		puts("ZERO");
	else
		puts("LOOP");
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--)
		MAIN();
	return 0;
}
