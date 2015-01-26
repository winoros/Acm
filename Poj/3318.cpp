/*
 * =====================================================================================
 *
 *       Filename:  3318.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/25 22:22:02
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

template<class T>
inline bool read(T &n) {
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}

long long a[510][510], b[510][510], c[510][510];

void MAIN() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			read(a[i][j]);
	for(int j = 0; j < n; ++j)
		for(int i = 0; i < n; ++i)
			read(b[i][j]);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			read(c[i][j]);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j) {
			long long sum = 0;
			for(int k = 0; k < n; ++k)
				sum += a[i][k] * b[j][k];
			if(sum != c[i][j]) {
				puts("NO");
				return ;
			}
		}
	puts("YES");
}

int main() {
	MAIN();
	return 0;
}
