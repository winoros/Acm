/*
 * =====================================================================================
 *
 *       Filename:  1021.cpp
 *
 *    Description:  solve the 1021th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/23 21:29:59
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

int a[50010], b[50010];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) 
		scanf("%d", &b[i]);
	sort(a, a+n), sort(b, b+m);
	for(int i = 0, j = m-1; i < n && j >= 0; ) {
		if(a[i] + b[j] == 10000) {
			puts("YES");
			return 0;
		} else if(a[i] + b[j] > 10000)
			j--;
		else 
			i++;
	}
	puts("NO");
	return 0;
}
