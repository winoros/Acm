/*
 * =====================================================================================
 *
 *       Filename:  4441.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/5 12:52:46
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

const int pivot = 100001;

struct node {
	int val, size, cnt1, cnt2;
	long long sum;
	node *ch[2], *p;
	node(): size(0), cnt1(0), cnt2(0), sum(0) {}
	bool d() {
		return p->ch[1] == this;
	}
	void setc(node *c, int d) {
		c->p = this;
		ch[d] = c;
	}
	void upd() {
		size = ch[0]->size + ch[1]->size + 1;
		sum = val + ch[0]->sum + ch[1]->sum;
		cnt1 = ch[0]->cnt1 + ch[1]->cnt1 + (val > 0);
		cnt2 = ch[0]->cnt2 + ch[1]->cnt2 + (val < 0);
	}
}Tnull, *null = &Tnull;

node *root, mem[200010], *tot;

void rot(node *now) {
    node *p = now->p;
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


node *getPred(node *now) {
	splay(now);
	now = now->ch[0];
	while(now->ch[1] != null)
		now = now->ch[1];
	return now;
}

node *getSucc(node *now) {
	splay(now);
	now = now->ch[1];
	while(now->ch[0] != null)
		now = now->ch[0];
	return now;
}

void del(node *now) {
	node *pred = getPred(now);
	node *succ = getSucc(now);
	splay(pred);
	splay(succ, pred);
	succ->ch[0] = null;
	succ->upd();
	pred->upd();
}

node *find(int rk) {
	for(node *now = root; ; ) {
		int sz = now->ch[0]->size;
		if(sz == rk)
			return now;
		else if(sz < rk)
			rk -= sz+1, now = now->ch[1];
		else
			now = now->ch[0];
	}
}

node *findd(int cnt) {
	for(node *now = root; ; ) {
		int sz = now->ch[0]->cnt2;
		if(cnt <= sz)
			now = now->ch[0];
		else if(cnt == sz+1) {
			if(now->val < 0)
				return now;
			else
				cnt -= sz, now = now->ch[1];
		} else {
			cnt -= sz + (now->val < 0);
			now = now->ch[1];
		}
	}
}

node *make(int val) {
	int pos = val > 0 ? val : pivot-val;
	mem[pos].val = mem[pos].sum = val;
	mem[pos].size = 1;
	mem[pos].cnt1 = val > 0, mem[pos].cnt2 = val < 0;
	mem[pos].ch[0] = mem[pos].ch[1] = mem[pos].p = null;
	return &mem[pos];
}

void insert(int pos, int val) {
	node *pred = find(pos);
	node *succ = find(pos+1);
	splay(pred);
	splay(succ, pred);
	succ->setc(make(val), 0);
	splay(succ->ch[0]);
	int cnt = root->ch[0]->cnt1 + 1;
	succ = findd(cnt);
	pred = getPred(succ);
	splay(pred, succ);
	pred->setc(make(-val), 1);
	pred->upd();
	succ->upd();
}

void del(int val) {
	if(val < 0)
		val = pivot - val;
	node *pred = getPred(mem+val);
	node *succ = getSucc(mem+val);
	splay(pred);
	splay(succ, pred);
	succ->ch[0] = null;
	succ->upd();
	pred->upd();
}

set<int> s;

void MAIN(int n) {
	char str[10];
    int x;
	s.clear();
	for(int i = 1; i < n; ++i)
		s.insert(i);
	mem[0].val = 0;
	mem[0].ch[0] = mem[0].ch[1] = mem[0].p = null;
	mem[0].size = 1;
	mem[0].cnt1 = mem[0].cnt2 = 0;
	mem[0].sum = 0;	
	mem[pivot].val = -1000000;
	mem[pivot].ch[0] = mem[pivot].ch[1] = mem[pivot].p = null;
	mem[pivot].size = 1;
	mem[pivot].cnt1 = 0, mem[pivot].cnt2 = 0;
	mem[pivot].sum = 0;
	root = &mem[0];
	root->setc(&mem[pivot], 1);
	root->upd();
	while(n--) {
		scanf("%s%d", str, &x);
		if(str[0] == 'i') {
			int minn = *s.begin();
			s.erase(minn);
			insert(x, minn);
		} else if(str[0] == 'r') {
			del(x), del(-x), s.insert(x);
		} else {
			node *pred = getPred(mem+x);
			node *succ = getSucc(mem+x+pivot);
			splay(pred);
			splay(succ, pred);
			printf("%I64d\n", succ->ch[0]->sum);
		}
	}
}

int main() {
	int n, cnt = 0;
	while(scanf("%d", &n) > 0) {
		printf("Case #%d:\n", ++cnt);
		MAIN(n);
	}
	return 0;
}
