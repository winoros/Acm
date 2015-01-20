/*===============================================================
*   
*   FILE NAME:  2479.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       09/09/2014 23:01:36
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <cctype>
#include <climits>
#include <stack>
#include <cmath>
#include <bitset>
#include <numeric>
#include <functional>

using namespace std;

const int inf = 1<<30;
int a[50010], dp[50010], l[50010], r[50010];

int main() {
	int nn;
	scanf("%d", &nn);
	while(nn--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", a+i);
		dp[0] = dp[n+1] = l[0] = r[n+1] = -inf;
		for(int i = 1; i <= n; i++)
			dp[i] = max(dp[i-1]+a[i], a[i]);
		for(int i = 1; i <= n; i++)
			l[i] = max(l[i-1], dp[i]);
		for(int i = n; i > 0; i--)
			dp[i] = max(dp[i+1]+a[i], a[i]);
		for(int i = n; i > 0; i--)
			r[i] = max(r[i+1], dp[i]);
		int ans = INT_MIN;
		for(int i = 1; i < n; i++)
			ans = max(ans, l[i]+r[i+1]);
		printf("%d\n", ans);
	}
	return 0;
}
