/*
 * =====================================================================================
 *
 *       Filename:  509e.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/31 21:30:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
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

char str[500100];
double sum[500010];

void init(int len) {
	sum[0] = 0;
	for(int i = 1; i <= len; ++i)
		sum[i] = sum[i-1] + 1.0/i;
}

double get(int i, int n) {
	double ret = 0;
	int l = i+1, r = n-i;
	ret += min(l, r);
	ret += min(l,r)*(sum[max(l,r)] - sum[min(l, r)]);
	ret += (n+1)*(sum[n] - sum[max(l, r)]) - (n - max(l, r));
	return ret;
}

void MAIN() {
	scanf("%s", str);
	int len = strlen(str);
	init(len);
	double ans = 0;
	for(int i = 0; i < len; ++i) {
		if(str[i] == 'I' || str[i] == 'E' || str[i] == 'A' || str[i] == 'O' || str[i] == 'U' || str[i] == 'Y') {
			ans += get(i, len);
		}
	}
	printf("%.11f\n", ans);
}

int main() {
	MAIN();
	return 0;
}
