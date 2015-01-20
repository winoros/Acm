/*
 * =====================================================================================
 *
 *       Filename:  4104.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/1 18:58:47
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

int a[1010];

int main() {
	int n;
	while(scanf("%d", &n) > 0) {
		for(int i = 0; i < n; ++i)
			scanf("%d", a+i);
		sort(a, a+n);
		int now_max = 0;
		for(int i = 0; i < n; ++i)
			if(a[i] > now_max+1)
				break;
			else
				now_max += a[i];
		printf("%d\n", now_max+1);
	}
	return 0;
}
