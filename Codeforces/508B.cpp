/*
 * =====================================================================================
 *
 *       Filename:  508B.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/28 0:39:03
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

char str[100010];
int a[100010];

void MAIN() {
	scanf("%s", &str);
	int n = strlen(str);
	for(int i = 0; i < n; ++i)
		a[i] = str[i] - '0';
	int pos = -1;
	for(int i = 0; i < n; ++i)
		if(a[i]&1 == 0) {
			if(a[i] < a[n-1])
				swap(a[i])
		}
}
