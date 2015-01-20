/*
 * =====================================================================================
 *
 *       Filename:  4044.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/9/15 20:01:17
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

struct node {
    int price, power;
};
vector<int> v[1010];
vector<node> thing[1010];
int dp[1010][210], son_ans[1010][210];
int n, m;

inline node make_node(int _price, int _power) {
    node ret;
    ret.price = _price, ret.power = _power;
    return ret;
}

void dfs(int now, int fa) {
    int sz = thing[now].size();
    memset(dp[now], 0, sizeof dp[now]);
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j < sz; j++)
            if(thing[now][j].price <= i)
                dp[now][i] = max(dp[now][i], thing[now][j].power);
    }
    sz = v[now].size();
    if(sz == 1 && fa != -1) {
        v[now].clear();
        thing[now].clear();
        return ;
    }
    memset(son_ans[now], 0x3f, sizeof son_ans[now]);
    for(int i = 0; i < sz; i++) {
        if(v[now][i] == fa)
            continue;
        dfs(v[now][i], now);
        for(int j = m; j >= 0; j--) {
            int maxx = 0;
            for(int k = 0; k <= j; k++)
                maxx = max(maxx, min(son_ans[now][j-k], dp[v[now][i]][k]));
            son_ans[now][j] = maxx;
        }
    }
    for(int i = m; i >= 0; i--)
        for(int j = 0; j <= i; j++)
            dp[now][i] = max(dp[now][i], dp[now][i-j] + son_ans[now][j]);
    v[now].clear(), thing[now].clear();
}

int main() {
    int nn;
    scanf("%d", &nn);
    while(nn--) {
        scanf("%d", &n);
        for(int i = 1; i < n; i++) {
            int _u, _v;
            scanf("%d%d", &_u, &_v);
            v[_u].push_back(_v);
            v[_v].push_back(_u);
        }
        scanf("%d", &m);
        for(int i = 1; i <= n; i++) {
            int k;
            scanf("%d", &k);
            for(int j = 0; j < k; j++) {
                int _price, _power;
                scanf("%d%d", &_price, &_power);
                thing[i].push_back(make_node(_price, _power));
            }
        }
        dfs(1, -1);
        printf("%d\n", dp[1][m]);
        
    }
    return 0;
}
