/*
 * =====================================================================================
 *
 *       Filename:  509c.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/31 22:17:23
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

int a[3];

void get(int now, int sum, bool first) {
	if(!first && now == sum)
		return ;
	if(now < sum) {
		if(now + 9-a[2] + now >= sum)
			a[2] += sum-now;
		else if(now + 9-a[2] + 9-a[1] >= sum)
			a[2] = 9, a[1] = sum-now - (9-a[2]);
		else {
			++a[0];
			a[2] = 9;
			a[1] = sum-a[0]-a[2];
		}
	} else {
		if(a[1] != 9) {
			now = now-a[2]+1;
			a[2] = 0, ++a[1];
			get(now, sum, false);
		} else {
			now = now-a[2]-a[1]+1;
			a[2] = a[1] = 0, ++a[0];
			get(now, sum, false);
		}
	}
}

void MAIN() {
	int n;
	scanf("%d", &n);
	int now = 0, target;
	a[0] = a[1] = a[2] = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &target);
		get(now, target, true);
		now = target;
		printf("%d\n", a[0]*100+a[1]*10+a[2]);
	}
}

int main() {
	MAIN();
	return 0;
}
