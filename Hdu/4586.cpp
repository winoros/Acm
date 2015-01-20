/*
 * =====================================================================================
 *
 *       Filename:  4586.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/25 18:23:47
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

int main() {
	int n;
	while(scanf("%d", &n) > 0) {
		int sum = 0;
		for(int i = 0, tmp; i < n; ++i) {
			scanf("%d", &tmp);
			sum += tmp;
		}
		int m;
		scanf("%d", &m);
		if(!sum)
			puts("0.00");
		else if(n == m)
			puts("inf");
		else
			printf("%.2f\n", sum*1.0 / (n-m));
		for(int i = 0, tmp; i < m; ++i)
			scanf("%d", &tmp);
	}
	return 0;
}
