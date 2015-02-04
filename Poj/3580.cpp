/*
 * =====================================================================================
 *
 *       Filename:  3580.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/4 14:11:28
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

const int inf = 0x3f3f3f3f;

struct node {
	int val, size, change, minn;
	bool reverse;
	node *ch[2], *p;
	node(): size(0), change(0), minn(inf), reverse(false) {}
	bool d() {
		return p->ch[1] == this;
	}
	void setc(node *c, int d) {
		c->p = this;
		ch[d] = c;
	}
	void add(int v) {
		val += v;
		change += v;
		minn += v;
	}
	void rev() {
		reverse ^= 1;
	}
	void upd() {
		size = ch[0]->size + ch[1]->size + 1;
		minn = min(val, min(ch[0]->minn, ch[1]->minn));
	}
	void relax();
} Tnull, *null = &Tnull;

void node::relax() {
	if(change != 0) {
		for(int i = 0; i < 2; ++i)
			if(ch[i] != null)
				ch[i]->add(change);
		change = 0;
	}
	if(reverse) {
		swap(ch[0], ch[1]);
		for(int i = 0; i < 2; ++i)
			if(ch[i] != null)
				ch[i]->rev();
		reverse = false;
	}
}

node *root, mem[200010], *tot;

node *make(int val) {
	tot->p = null;
	tot->val = tot->minn = val;
	tot->ch[0] = tot->ch[1] = null;
	tot->reverse = false;
	tot->change = 0;
	tot->size = 1;
	return tot++;
}

int a[200010];

node *build(int l, int r) {
	if(l > r)
		return null;
	int m = (l+r)>>1;
	node *now = make(a[m]);
	now->setc(build(l, m-1), 0);
	now->setc(build(m+1, r), 1);
	now->upd();
	return now;
}

void rot(node *now) {
	node *p = now->p;
	p->relax();
	now->relax();
	int d = now->d();
	p->setc(now->ch[!d], d);
	now->p = p->p;
	if(p->p != null)
		p->p->setc(now, p->d());
	else
		root = now;
	now->setc(p, !d);
	p->upd();
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
	if(now->p == root)
		now = root;
}

node *find(int rk) {
	for(node *now = root; ; ) {
		now->relax();
		int sz = now->ch[0]->size;
		if(rk == sz)
			return now;
		else if(rk > sz)
			rk -= sz+1, now = now->ch[1];
		else
			now = now->ch[0];
	}
}

node *get(int l, int r) {
	node *_l = find(l-1);
	node *_r = find(r);
	splay(_l);
	splay(_r, _l);
	return _r->ch[0];
}

void inorder(node *now) {
	if(now == null)
		return ;
	now->relax();
	inorder(now->ch[0]);
	printf("%d ", now->val);
	inorder(now->ch[1]);
}

void MAIN() {
	int n;
	scanf("%d", &n);
	a[0] = inf, a[n+1] = inf;
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	tot = mem;
	root = build(0, n+1);
	int m;
	scanf("%d", &m);
	char str[10];
	int x, y, z;
	for(int i = 0; i < m; ++i) {
		scanf("%s%d", str, &x);
		if(str[0] == 'D') {
			node *pred = find(x-1);
			node *succ = find(x+1);
			splay(pred);
			splay(succ, pred);
			succ->ch[0] = null;
			succ->upd();
		} else {
			scanf("%d", &y);
			if(str[0] == 'I') {
				node *pred = find(x);
				node *succ = find(x+1);
				splay(pred);
				splay(succ, pred);
				succ->setc(make(y), 0);
				succ->upd();
			} else if(str[0] == 'M') {
				node *now = get(x, y+1);
				printf("%d\n", now->minn);
			} else if(str[0] == 'R' && str[3] == 'E') {
				node *now = get(x, y+1);
				now->rev();
			} else {
				scanf("%d", &z);
				if(str[0] == 'A') {
					node *now = get(x, y+1);
					now->add(z);
				} else {
					int len = y-x+1;
					z = ((z%len) + len) %len;
					if(z == 0)
						continue;
					y = y-z+1;
					z = x+len-1;
					node *now = get(x, y);
					now->rev();
					now = get(y, z+1);
					now->rev();
					now = get(x, z+1);
					now->rev();
				}
			}
		}
		//inorder(root);
		//puts("");
	}
}

int main() {
	MAIN();
	return 0;
}
