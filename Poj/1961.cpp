/*
 * =====================================================================================
 *
 *       Filename:  1961.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/23 15:24:54
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

int next[1000010];
char str[1000010];

void make_kmp(int len) {
	next[0] = -1;
	int i = 0, j = -1;
	while(i < len) {
		if(j == -1 || str[i] == str[j]) {
			++i, ++j;
			next[i] = j;
		} else
			j = next[j];
	}
}

void MAIN(int len) {
	scanf("%s", str);
	make_kmp(len);
	for(int i = 2; i <= len; ++i)
		if(i % (i-next[i]) == 0 && next[i] != 0)
			printf("%d %d\n", i, i / (i-next[i]));
}

int main() {
	int len, n = 0;
	while(scanf("%d", &len) && len != 0) {
		printf("Test case #%d\n", ++n);
		MAIN(len);
		puts("");
	}
	return 0;
}
