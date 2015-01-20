/*
 * =====================================================================================
 *
 *       Filename:  1026.cpp
 *
 *    Description:  solve the 1026th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/23 21:42:24
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

int a[100010];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	char str[10];
	scanf("%s", str);
	sort(a, a+n);
	scanf("%d", &n);
	while(n--) {
		int tmp;
		scanf("%d", &tmp);
		printf("%d\n", a[tmp-1]);
	}
	return 0;
}
