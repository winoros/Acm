/*
 * =====================================================================================
 *
 *       Filename:  4811.cpp
 *
 *    Description
 *
 *        Version:  1.0
 *        Created:  2014/9/18 13:51:28
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

typedef long long ll;

inline ll cal (ll u) {
    if (u <= 2)
        return u;
    else
        return 2;
}

int main () {
    int R, Y, B;
    while (scanf("%d%d%d", &R, &Y, &B) > 0) {
        int h = cal(R) + cal(Y) + cal(B);
        ll n = R + Y + B;
        ll ans = 0;
        for (int i = 0; i < n && i < h; i++)
            ans += i;
        if (n > h)
            ans += (long long)h * (n-h);;
		printf("%I64d\n", ans);
    }    
    return 0;
}
