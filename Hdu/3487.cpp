/*
 * =====================================================================================
 *
 *       Filename:  3487.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/2 21:00:55
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
    int val, size;
    bool reverse;
    node *p, *ch[2];
    node (): size(0), reverse(false) {}
    bool d() {
        return p->ch[1] == this;
    }
    void setc(node *c, int d) {
        c->p = this;
        ch[d] = c;
    }
    void rev() {
        reverse ^= 1;
    }
    void upd() {
        size = ch[0]->size + ch[1]->size + 1;
    }
    void relax();
} Tnull, *null = &Tnull;

void node::relax() {
    if(reverse) {
        swap(ch[0], ch[1]);
        for(int i = 0; i < 2; ++i)
            if(ch[i] != null)
                ch[i]->rev();
        reverse = false;
    }
}

node *root, mem[300010], *tot;

void rot(node *now) {
    node *p = now->p;
    p->relax();
    now->relax();
    int d = now->d();
    p->setc(now->ch[!d], d);
    now->p = p->p;
    if(now->p != null)
        p->p->setc(now, p->d());
    now->setc(p, !d);
    p->upd();
    if(now->p == null)
        root = now;
}

void splay(node *now, node *goal = null) {
    while(now->p != goal) {
        if(now->p->p == goal)
            rot(now);
        else {
            now->d() == now->p->d() ? rot(now->p) : rot(now);
            rot(now);
        }
    }
    now->upd();
    if(now->p == null)
        root = now;
}

node *find(int rk) {
    for(node *now = root; ; ) {
        now->relax();
        int sz = now->ch[0]->size;
        if(sz == rk)
            return now;
        else if(rk > sz)
            rk -= sz+1, now = now->ch[1];
        else
            now = now->ch[0];
    }
}

node *&get(int l, int r) { //[l,r)
    node *_l = find(l-1);
    node *_r = find(r);
    splay(_l);
    splay(_r, _l);
    return _r->ch[0];
}

node *make_node(int val) {
    tot->val = val;
    tot->ch[0] = tot->ch[1] = null;
    tot->reverse = false;
    tot->size = 1;
    return tot++;
}

node *build(int l, int r) {
    if(l > r)
        return null;
    int m = (l+r)>>1;
    node *ret = make_node(m);
    ret->setc(build(l, m-1), 0);
    ret->setc(build(m+1, r), 1);
    ret->upd();
    return ret;
}

int ans[300010], anslen;

void inorder(node *now) {
    if(now == null)
        return ;
    now->relax();
    inorder(now->ch[0]);
    ans[anslen++] = now->val;
    inorder(now->ch[1]);
}

void MAIN(int n, int m) {
    tot = mem;
    root = build(0, n+1);
    root->p = null;
    char str[6];
    int x, y, z;
    for(int i = 0; i < m; ++i) {
        scanf("%s%d%d", str, &x, &y);
        if(str[0] == 'F') {
            node *now = get(x, y+1);
            now->rev();
        } else {
            scanf("%d", &z);
            if(x == z+1)
                continue;
            else if(x <= z)
                z += (y-x+1);
            else {
                swap(y, z);
                swap(x, y);
                ++x, --y;
            }
            node *now = get(x, y+1);
            now->rev();
            now = get(y+1, z+1);
            now->rev();
            now = get(x, z+1);
            now->rev();
        }
    }
    node *now = get(1, n+1);
    anslen = 0;
    inorder(now);
    for(int i = 0; i < n; ++i)
        printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
}

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) && n != -1)
        MAIN(n, m);
    return 0;
}
