/*
 * =====================================================================================
 *
 *       Filename:  1060.cpp
 *
 *    Description:  solve the 1060th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/27 20:47:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>

using namespace std;

queue<pair<int, int> > q;
bool used[(1<<16)+10];

int change(int now, int pos) {
	now ^= (1<<pos);
	if(pos+4 < 16)
		now ^= (1<<(pos+4));
	if(pos-4 >= 0)
		now ^= (1<<(pos-4));
	if(pos%4 != 0 && pos > 0)
		now ^= (1<<(pos-1));
	if(pos%4 != 3 && pos < 15)
		now ^= (1<<(pos+1));
	return now;
}

int bfs(int src) {
	if(src == 0 || src == (1<<16)-1)
		return 0;
	q.push(make_pair(src, 0));
	used[src] = true;
	while(!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		for(int i = 0; i < 16; i++) {
			int nxt = change(now.first, i);
			if(nxt == 0 || nxt == (1<<16)-1)
				return now.second+1;
			if(!used[nxt])
				q.push(make_pair(nxt, now.second+1)), used[nxt] = true;
		}
	}
	return -1;
}

int main() {
	char c = 0;
	int init = 0;
	for(int i = 0; i < 16; i++) {
		while(!isalpha(c))
			c = getchar();
		if(c == 'b')
			init |= (1<<i);
		c = 0;
	}
	int ans = bfs(init);
	if(ans == -1)
		puts("Impossible");
	else 
		printf("%d\n", ans);
	return 0;
}
