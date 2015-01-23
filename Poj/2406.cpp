/*
 * =====================================================================================
 *
 *       Filename:  2406.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/23 14:58:26
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

void MAIN() {
	int len = strlen(str);
	make_kmp(len);
	if(len % (len - next[len]) == 0)
		printf("%d\n", len / (len - next[len]));
	else
		puts("1");
}

int main() {
	while(scanf("%s", str) && strcmp(str, ".") != 0)
		MAIN();
	return 0;
}
