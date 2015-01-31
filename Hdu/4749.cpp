/*
 * =====================================================================================
 *
 *       Filename:  4749.cpp
 *
 *    Description:   
 *
 *        Version:  1.0
 *        Created:  2015/1/31 15:24:43
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

int n, m, p;
int a[100010], b[100010];
int bit[30];
int low[100010], eq[100010];
int next[100010];

int get(int i) {
    int res = 0;
    for (; i; i -= i & -i) res += bit[i];
    return res;
}

void add(int i, int x) {
    for (; i <= p; i += i & -i) bit[i] += x;
}

void init() {
    fill(bit, bit + p + 1, 0);
    low[0] = eq[0] = 0;
    for (int i = 1; i <= m; i++) {
        low[i] = get(b[i] - 1);
        eq[i] = get(b[i]) - low[i];
        add(b[i], 1);
    }
}

int last;

bool ok(int *a, int lim, int x, int j) {
    while (last < lim) add(a[last++], -1);
    int l = get(x - 1), e = get(x) - l;
    return l == low[j] && e == eq[j];
}

int kmp() {
	memset(bit, 0, sizeof bit);
    int j = 0;
	int ret = 0;
    next[1] = 0;
    last = 1;
    add(b[1], 1);
    for (int i = 2; i <= m; i++) {
        while (j && !ok(b, i - j, b[i], j + 1)) {
            j = next[j];
        }
        if (j == 0 || ok(b, i - j, b[i], j + 1)) j++;
        next[i] = j;
        add(b[i], 1);
    }
	memset(bit, 0, sizeof bit);
    j = 0;
    last = 1;
    for (int i = 1; i <= n; i++) {
        while (j && !ok(a, i - j, a[i], j + 1))
            j = next[j];
        if (j == 0 || ok(a, i - j, a[i], j + 1))
            j++;
        if (j == m) {
			++ret;
            j = 0;
        }
        add(a[i], 1);
    }
	return ret;
}

void MAIN() {
	for (int i = 1; i <= n; i++)
         scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
    init();
    printf("%d\n", kmp());
}

int main() {
    while (scanf("%d%d%d", &n, &m, &p) > 0)
        MAIN();
	return 0;
}

