/*
 * =====================================================================================
 *
 *       Filename:  1081.cpp
 *
 *    Description:  solve the 1081th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/25 23:41:47
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
	bool used[45] = { false };
	int fibo[45];
	fibo[0] =1, fibo[1] = 2;
	for(int i = 2; i < 45; i++)
		fibo[i] = fibo[i-1] + fibo[i-2];
	int n, k;
	scanf("%d%d", &n, &k);
	if(fibo[n] < k) {
		puts("-1");
		return 0;
	}
	for(int i = n; i > 0; i--)
		if(fibo[i-1] < k)
			used[i] = true, k-=fibo[i-1];
	for(int i = n; i >= 1; i--)
		printf("%d", used[i]);
	puts("");
	return 0;
}
