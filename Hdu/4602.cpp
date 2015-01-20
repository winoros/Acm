/*
 * =====================================================================================
 *
 *       Filename:  4602.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/11/1 15:08:25
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

const int mod = 1e9+7;

long long quick_pow(int n) {
	if(!n)
		return 1;
	long long ret = quick_pow(n>>1);
	ret = ret * ret %mod;
	if(n&1)
		ret = ret * 2 %mod;
	return ret;
}

int main() {
	int nn;
	scanf("%d", &nn);
	while(nn--) {
		int n, k;
		scanf("%d%d", &n, &k);
		long long ret;
		if(k > n)
			ret = 0;
		else if(k == n)
			ret = 1;
		else if(k == n-1)
			ret = 2;
		else
			ret = (n-k+3) * quick_pow(n-k-2) %mod;
		printf("%I64d\n", ret);
	}
	return 0;
}
