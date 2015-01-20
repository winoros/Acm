/*
 * =====================================================================================
 *
 *       Filename:  5072.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/22 14:45:37
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

vector<int> fac[100010];
int cnt[100010];
int a[100010];

int main() {
	for(int i = 2; i <= 100000; ++i)
		for(int j = i; j <= 100000; j += i)
			fac[j].push_back(i);
	int nn;
	scanf("%d", &nn);
	for(int ii = 1; ii <= nn; ++ii) {
		int n;
		scanf("%d", &n);
		memset(cnt, 0, sizeof cnt);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			int sz = fac[a[i]].size();
			for(int j = 0; j < sz; ++j)
				cnt
		}
	}
}
