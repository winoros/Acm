/*
 * =====================================================================================
 *
 *       Filename:  1911.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/7 20:00:06
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

long long a, b, c, sum[1000010], dp[1000010];

inline long long dy(int i, int j) {
	return (dp[i] + a*sum[i]*sum[i] - b*sum[i]) - (dp[j] + a*sum[j]*sum[j] - b*sum[j]);
}

inline long long dx(int i, int j) {
	return 2*a*(sum[i]-sum[j]);
}

inline long long func(long long x) {
	return a*x*x + b*x + c;
}

inline double grad(int i, int j) {
	return dy(i, j)*1.0/dx(i, j);
}

long long que[1000010];
int head, tail;

int main() {
	int n;
	scanf("%d", &n);
	scanf("%lld%lld%lld", &a, &b, &c);
	sum[0] = 0;
	for(int i = 1, num; i <= n; ++i) {
		scanf("%d", &num);
		sum[i] = sum[i-1] + num;
	}
	head = tail = 0;
	que[head] = dp[0] = 0;
	for(int i = 1; i <= n; ++i) {
		while(head < tail && grad(que[head], que[head+1]) <= sum[i])
			++head;
		dp[i] = dp[que[head]] + func(sum[i] - sum[que[head]]);
		while(head < tail && grad(que[tail], que[tail-1]) > grad(que[tail], i))
			--tail;
		que[++tail] = i;
	}
	printf("%lld\n", dp[n]);
	return 0;
}
