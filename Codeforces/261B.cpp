/*
 * =====================================================================================
 *
 *       Filename:  261B.cpp
 *
 *    Description: 
 *
 *        Version:  1.0
 *        Created:  2014/12/1 23:01:12
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

double fac[55], f[55][55][55];
int a[55];

int main() {
	fac[0] = 1;
	for(int i = 1; i < 51; ++i)
		fac[i] = fac[i-1] * i;
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a+i);
	int vol;
	scanf("%d", &vol);
	int tot = 0;
	for(int i = 1; i <= n; ++i)
		tot += a[i];
	if(tot <= vol)
		printf("%d\n", n);
	else {
		for(int i = 1; i <= n; ++i)
			f[0][0][i] = 1;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(i-j)
					for(int k = n-1; k >= 1; --k)
						for(int now = vol; now >= a[i]; --now)
							f[now][k][j] += f[now-a[i]][k-1][j];
		double ans = 0;
		for(int i = 1; i <= n; ++i)
			for(int now = vol; a[i] + now > vol && now >= 0; --now)
				for(int k = 1; k < n; ++k)
					ans += f[now][k][i] * fac[k] * fac[n-k-1] * k;
		ans /= fac[n];
		printf("%.11f\n", ans);
	}
	return 0;
}
