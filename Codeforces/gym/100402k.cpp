/*
 * =====================================================================================
 *
 *       Filename:  100402k.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/3/10 19:24:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

bool dp[60][70];
int pre[60][70];
long long a[60];
int cnt[60];

long long get(int one, int myOne, long long &pre) {
	//std::cout << one << " " << myOne << " " << pre << std::endl;
	long long ret = 0;
	int preOne = 0;
	for(long long tmp = pre; tmp != 0; tmp>>=1)
		if(tmp&1)
			++preOne;
	int del = 0, add;
	if(myOne+preOne > one)
		del = (myOne+preOne-one)/2;
	add = myOne - del;
	//std::cout << add << " " << del << std::endl;
	long long tmpp = pre;
	for(int i = 0; add > 0 || del > 0; ++i) {
		//std::cout << (pre&1) << " " << !(pre&1) << " " << del << " " << add << std::endl;
		if((del > 0 && pre&1) || (add > 0 && !(pre&1))) {
		//	puts("yes");
			ret |= 1LL<<i;
		}
		del -= pre&1;
		add -= !(pre&1);
		pre>>=1;
	}
	pre = tmpp^ret;
	return ret;
}

void MAIN() {
	int n;
	scanf("%d", &n);
	int len = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%I64d", &a[i]);
		int tmp = 0;
		while(a[i]) {
			++tmp;
			if(a[i]&1)
				++cnt[i];
			a[i]>>=1;
		}
		len = std::max(len, tmp);
	}
	dp[0][0] = true;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= len; ++j)
			if(dp[i][j]) {
				int more = 0;
				if(j+cnt[i] > len)
					more = (j+cnt[i]-len);
				int pt1 = j-more, pt2 = cnt[i]-more;
				while(pt1 >= 0 && pt2 >= 0) {
					dp[i+1][pt1+pt2] = true, pre[i+1][pt1+pt2] = j;
					--pt1, --pt2;
				}
			}
	}
	if(!dp[n][0])
		puts("impossible");
	else {
		int nowXor[60];
		nowXor[n] = 0;
		for(int i = n-1; i > 0; --i)
			nowXor[i] = pre[i+1][nowXor[i+1]];
		//for(int i = 1; i <= n; ++i)
		//	printf("%d%c", nowXor[i], i == n ? '\n' : ' ');
		long long state = 0;
		for(int i = 1; i <= n; ++i)
			//get(nowXor[i], cnt[i-1], state);
			printf("%I64d%c", get(nowXor[i], cnt[i-1], state), i == n ? '\n' : ' ');
	}
}

int main() {
	MAIN();
	return 0;
}
