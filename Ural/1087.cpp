/*
 * =====================================================================================
 *
 *       Filename:  1087.cpp
 *
 *    Description:  solve the 1087th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/26 2:59:22
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

int sg[10010];

int main() {
	int m[55], n, mm;
	scanf("%d%d", &n, &mm);
	for(int i = 0; i < mm; i++)
		scanf("%d", &m[i]);
	sg[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < mm; j++) {
			if(i-m[j] >= 0 && !sg[i-m[j]])
				sg[i] = 1;
		}
	}
	printf("%d\n", 2-sg[n]);
	return 0;
}
