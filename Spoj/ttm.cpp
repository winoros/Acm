/*
 * =====================================================================================
 *
 *       Filename:  4348.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/6/4 21:49:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

struct node {
    node *ch[2];
    int delta, len;
    long long sum;
    void upd() {
        sum = ch[0]->sum + ch[1]->sum + delta * 1LL * len;
    }
} null, *Tnull = &null;

node mem[3000010];
node *tot, *root[100010];

node* makeNode(int l, int r, long long val, int _delta = 0) {
    tot->ch[0] = tot->ch[1] = Tnull;
    tot->delta = _delta;
    tot->sum = val;
    tot->len = r - l + 1;
    return tot ++;
}

void build(node *&now, int l, int r) {
    now = makeNode(l, r, 0);
    if(l == r) {
        scanf("%lld", &now->sum);
    } else {
        int m = (l + r) >> 1;
        build(now->ch[0], l, m);
        build(now->ch[1], m + 1, r);
        now->upd();
    }
}

void update(node *pre, node *&now, int _l, int _r, int val, int l, int r) {
    if(_l <= l && r <= _r) {
        now = tot ++;
        *now = *pre;
        now->sum += val * 1LL * now->len;
        now->delta += val;
    } else if(l <= _r && _l <= r) {
        now = tot ++;
        *now = *pre;
        int m = (l + r) >> 1;
        update(pre->ch[0], now->ch[0], _l, _r, val, l, m);
        update(pre->ch[1], now->ch[1], _l, _r, val,  m + 1, r);
        now->upd();
    }
}

long long query(node *now, int _l, int _r, int _delta, int l, int r) {
    long long ret = 0;
    if(_l <= l && r <= _r) {
        ret = now->sum + _delta * 1LL * now->len;
    } else if(l <= _r && _l <= r) {
        _delta += now->delta;
        int m = (l + r) >> 1;
        ret += query(now->ch[0], _l, _r, _delta, l, m);
        ret += query(now->ch[1], _l, _r, _delta, m + 1, r);
    }
    return ret;
}

void MAIN(int n, int m) {
    tot = mem;
    int time = 0;
    build(root[time], 1, n);
    char str[3];
    for(int i = 0, x, y, z; i < m; ++i) {
        scanf("%s%d", str, &x);
        if(str[0] == 'B') {
        	time = x;
        } else {
            scanf("%d", &y);
            if(str[0] == 'Q') {
                printf("%lld\n", query(root[time], x, y, 0, 1, n));
            } else {
                scanf("%d", &z);
                if(str[0] == 'C') {
                    ++time;
                    update(root[time - 1], root[time], x, y, z, 1, n);
                } else {
                    printf("%lld\n", query(root[z], x, y, 0, 1, n));
                }
            }
        }
    }
}

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) == 2)
        MAIN(n, m);
    return 0;
}
