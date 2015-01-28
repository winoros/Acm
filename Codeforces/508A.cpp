/*
 * =====================================================================================
 *
 *       Filename:  508A.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/28 0:29:46
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

int a[1010][1010];

bool judge(int x, int y) {
	int cnt = 0;
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j <2; ++j)
			cnt += a[x+i][j+y];
	return cnt == 4;
}

void MAIN() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= k; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
		if(judge(x, y) || judge(x-1, y-1) || judge(x-1, y) || judge(x, y-1)) {
			printf("%d\n", i);
			return ;
		}
	}
	puts("0");
}

int main() {
	MAIN();
	return 0;
}
