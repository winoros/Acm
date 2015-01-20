/*
 * =====================================================================================
 *
 *       Filename:  1033.cpp
 *
 *    Description:  solve the 1033th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/25 17:07:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>

using namespace std;

char atlas[350][350];
int n;
int d[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
bool used[350][350];
queue<pair<int, int > > q;

int bfs() {
	q.push(make_pair(0, 0));
	q.push(make_pair(n-1, n-1));
	used[0][0] = used[n-1][n-1] = true;
	int cnt = 0;
	while(!q.empty()) {
		pair<int, int> front = q.front(); q.pop();
		int tx = front.first, ty = front.second;
		for(int i = 0; i < 4; i++) {
			if(tx + d[i][0] >= 0 && tx + d[i][0] < n
				&& ty + d[i][1] >= 0 && ty + d[i][1] < n
				&& atlas[tx+d[i][0]][ty+d[i][1]] == '.') {
					if(!used[tx+d[i][0]][ty+d[i][1]]) {
					q.push(make_pair(tx+d[i][0], ty+d[i][1]));
					used[tx+d[i][0]][ty+d[i][1]] = true;
					}
			}
			else  
				cnt++;
		}
	}
	return cnt;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%s", atlas[i]);
	printf("%d\n", (bfs()-4) * 9);
	return 0;
}
