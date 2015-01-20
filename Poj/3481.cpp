/*
 * =====================================================================================
 *
 *       Filename:  3481.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/8 21:04:59
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
#include <ctime>

struct node {
	int l, r, prefix, data;
};

class treap {
private:
	node p[1000010];
	int root, cnt;
	void rot_r(int &now) {
		int tmp = p[now].l;
		p[now].l = p[tmp].r;
		p[tmp].r = now;
		now = tmp;
	}
	void rot_l(int &now) {
		int tmp = p[now].r;
		p[now].r = p[tmp].l;
		p[tmp].l = now;
		now = tmp;
	}
	void _insert(int &now, int data, int prefix) {
		if(now == -1) {
			now = ++cnt;
			p[now].data = data;
			p[now].prefix = prefix;
			p[now].l = p[now].r = -1;
		} else if(data <= p[now].data) {
			_insert(p[now].l, data, prefix);
			if(p[p[now].l].prefix > p[now].prefix)
				rot_r(now);
		} else {
			_insert(p[now].r, data, prefix);
			if(p[p[now].r].prefix > p[now].prefix)
				rot_l(now);
		}
	}
	void _remove(int &now, int data) {
		if(p[now].data == data) {
			if(p[now].l == -1 || p[now].r == -1) {
				if(p[now].l != -1)
					now = p[now].l;
				else
					now = p[now].r;
			} else {
				if(p[p[now].l].prefix < p[p[now].r].prefix) {
					rot_r(now);
					_remove(p[now].r, data);
				} else {
					rot_l(now);
					_remove(p[now].l, data);
				}
			}
		} else if(data < p[now].data)
			_remove(p[now].l, data);
		else
			_remove(p[now].r, data);
	}
public:
	treap() {
		root = cnt = -1;
	}
	void insert(int data, int prefix) {
		_insert(root, data, prefix);
	}
	void remove(int data) {
		_remove(root, data);
	}
	int find_min() {
		int now = root;
		if(now == -1) {
			puts("0");
			return -1;
		}
		while(p[now].l != -1)
			now = p[now].l;
		printf("%d\n", p[now].prefix);
		return p[now].data;
	}
	int find_max() {
		int now = root;
		if(now == -1) {
			puts("0");
			return -1;
		}
		while(p[now].r != -1)
			now = p[now].r;
		printf("%d\n", p[now].prefix);
		return p[now].data;
	}
};

treap a;

int main() {
	int op;
	while(scanf("%d", &op) && op) {
		if(op == 1) {
			int data, prefix;
			scanf("%d%d", &prefix, &data);
			a.insert(data, prefix);
		} else if(op == 2) {
			int data = a.find_max();
			if(data != -1)
				a.remove(data);
		} else {
			int data = a.find_min();
			if(data != -1)
				a.remove(data);
		}
	}
	return 0;
}
