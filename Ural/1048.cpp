/*
 * =====================================================================================
 *
 *       Filename:  1048.cpp
 *
 *    Description:  slove the 1048th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/24 20:50:30
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

int ans[1000010];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		ans[i] = a+b;
	}
	for(int i = n-1; i >= 0; i--)
		if(ans[i] > 9) ans[i]-= 10, ans[i-1]++;
	for(int i = 0; i < n; i++)
		printf("%d", ans[i]);
	puts("");
	return 0;
}
