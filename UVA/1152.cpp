/*===============================================================
*   
*   FILE NAME:  1152.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       02/14/2015 15:33:35
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
#include <bits/stdc++.h>

using namespace std;

long long a[4][4010], b[4010*4010];

void MAIN() {
	int n;
	scanf("%d", &n);
	for(int j = 0; j < n; ++j)
		for(int i = 0; i < 4; ++i)
			scanf("%lld", &a[i][j]);
	int len = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			b[len++] = a[0][i]+a[1][j];
	sort(b, b+n*n);
	int ans = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j) {
			long long sum = a[2][i]+a[3][j];
			ans += upper_bound(b, b+len, -sum) - lower_bound(b, b+len, -sum);
		}
	printf("%d\n", ans);
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		MAIN();
		if(n != 0)
			puts("");
	}
	return 0;
}
