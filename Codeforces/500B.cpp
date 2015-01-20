/*
 * =====================================================================================
 *
 *       Filename:  500B.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/30 23:33:27
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

bool ok[310][310];
int a[310], pos[310];

void floyd(int n) {
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(ok[i][k] && ok[k][j])
					ok[i][j] = true;
}

int main() {
	int n;
	char str[310];
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
		pos[a[i]] = i;
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%s", str);
		for(int j = 1; j <= n; ++j)
			ok[i][j] = str[j-1]-'0';
	}
	floyd(n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < pos[i]; ++j)
			if(a[j] > i && ok[pos[i]][j]) {
				swap(a[j], a[pos[i]]);
				swap(pos[a[j]], pos[a[pos[i]]]);
				break;
			}
	}
	for(int i = 1; i <= n; ++i)
		printf("%d%c", a[i], i == n ? '\n' : ' ');
	return 0;
}
