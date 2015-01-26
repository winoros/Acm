/*
 * =====================================================================================
 *
 *       Filename:  4694.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/26 12:32:52
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

vector<int> succ[50010], pred[50010], bucket[50010];

int fa[50010], id[50010],semi[50010], dom[50010], anc[50010], label[50010];
int size[50010], child[50010];
int timestamp; //initial with -1

void tarjan_dfs(int now) {
	semi[now] = ++timestamp;
	id[timestamp] = now;
	bucket[now].clear();
	anc[now] = 0, label[now] = now;
	size[now] = 1, child[now] = 0;
	int sz = succ[now].size();
	for(int i = 0; i < sz; ++i) {
		if(semi[succ[now][i]] == 0) {
			dfs(succ[now][i]);
			fa[succ[now][i]] = now;
		}
	}
}

void compress(int v) {
	if(anc[anc[v]] != 0) {
		compress(anc[v]);
		if(semi[label[anc[v]]] < semi[label[v]])
			lable[v] = label[anc[v]];
		anc[v] = anc[anc[v]];
	}
}

int eval(int v) {
	if(anc[v] == 0)
		return v;
	else {
		compress(v);
		return semi[label[anc[v]]] >= semi[label[v]] ? 
			labe[v] : label[anc[v]];
	}
}

void link(int v, int w) {
	int s = w;
	while(semi[label[w]] < semi[label[child[s]]]) {

	}
}
