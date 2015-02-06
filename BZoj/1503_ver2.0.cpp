/*
 * =====================================================================================
 *
 *       Filename:  1503_ver2.0.cpp
 *
 *    Description:  
 *
 *        Version:  2.0
 *        Created:  2015/2/6 21:52:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include<bits/stdc++.h>

using namespace std;

struct node {
	int val, cnt, size;
	node *ch[2], *p;
	node (): cnt(0), size(0) {}
	bool d() {
		return p->ch[1] == this;
	}
	void setc(node *c, int d) {
		c->p = this;
		ch[d] = c;
	}
	void upd() {
		size = cnt + ch[0]->size + ch[1]->size;
	}
}Tnull, *null = &Tnull;

node *root, mem[100010], *tot;

void rot(node *now) {
	node *p = now->p;
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
			rot(now->d() == now->p->d() ? now->p : now);
			rot(now);
		}
	}
	now->upd();
}

node *find(int rk) {
	for(node *now = root; ; ) {
		int sz = now->ch[0]->size;
		if(sz >= rk)
			now = now->ch[0];
		else if(sz + now->cnt >= rk)
			return now;
		else 
			rk -= sz + now->cnt, now = now->ch[1];
	}
}

node *upper_bound(int val) {
	node *ret = null;
	for(node *now = root; ; ) {
		if(now == null)
			return ret;
		if(now->val <= val)
			now = now->ch[1];
		else
			ret = now, now = now->ch[0];
	}
}

node *make(int val) {
	tot->val = val;
	tot->cnt = tot->size = 1;
	tot->ch[0] = tot->ch[1] = tot->p = null;
	return tot++;
}

void insert(int val) {
	node *now = root;
	while(1) {
		if(now->val == val) {
			++now->cnt;
			++now->size;
			splay(now);
			return ;
		} else if(now->val > val) {
			if(now->ch[0] == null) {
				now->setc(make(val), 0);
				splay(now->ch[0]);
				return ;
			} else
				now = now->ch[0];
		} else {
			if(now->ch[1] == null) {
				now->setc(make(val), 1);
				splay(now->ch[1]);
				return ;
			} else
				now = now->ch[1];
		}
	}
}

void MAIN() {
	int n, minn;
	scanf("%d%d", &n, &minn);
	root = mem, tot = mem+1;
	root->val = 3000000;
	root->ch[0] = root->ch[1] = root->p = null;
	root->size = root->cnt = 1;
	char str[5];
	int x;
	int final_ans = 0, change = 0;
	while(n--) {
		scanf("%s%d", str, &x);
		if(str[0] == 'I') {
			if(x < minn)
				continue;
			else
				insert(x-change);
		} else if(str[0] == 'A') {
			change += x;
		} else if(str[0] == 'S') {
			change -= x;
			node *now = upper_bound(minn-change-1);
			splay(now);
			final_ans += now->ch[0]->size;
			now->setc(null, 0);
			now->upd();
		} else {
			x = root->size - x;
			if(x <= 0)
				puts("-1");
			else {
				node *now = find(x);
				printf("%d\n", now->val+change);
			}
		}
	}
	printf("%d\n", final_ans);
}

int main() {
	MAIN();
	return 0;
}
