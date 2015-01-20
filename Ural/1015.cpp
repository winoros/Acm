/*
 * =====================================================================================
 *
 *       Filename:  1015.cpp
 *
 *    Description:  solve the 1015th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/28 19:26:09
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

map<int, int> m;
vector<vector<int> > v(300);

int rot[3][4] = { { 2, 4, 3, 5}, { 0, 4, 1, 5}, { 0, 2, 1, 3} };

int main() {
	int n, num[6], len = 1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int hash_num = 0;
		scanf("%d%d%d%d%d%d", &num[0], &num[1], &num[2], &num[4], &num[3], &num[5]);
		int st;
		for(st = 0; st < 6; st++)
			if(num[st] == 1)
				break;
		hash_num = num[st]+num[st^1]*10;
		st/=2;
		int min = 7, pos;
		for(int j = 0; j < 4; j++)
			if(min > num[rot[st][j]])
				min = num[rot[st][j]], pos = j;
		int delta;
		if(num[rot[st][(pos+1)%4]] < num[rot[st][(pos+3)%4]])
			delta = 1;
		else 
			delta = 3;
		int tmp = 0;
		for(int j = 0; j < 4; j++) {
			printf("%d---\n", num[rot[st][(pos+j*delta)%4]]);
			tmp = tmp*10 + num[rot[st][(pos+j*delta)%4]];
		}
		printf("----%d\n", tmp);
		hash_num = tmp*100 + hash_num;
		pos = m[hash_num];
		printf("%d  %d---\n", hash_num, pos);
		if(pos)
			v[pos].push_back(i);
		else {
			v[len].push_back(i);
			m[hash_num] = len++;
		}
			
	}
	printf("%d\n", len-1);
	for(int i = 1; i < len; i++) {
		int sz = v[i].size();
		for(int j = 0; j < sz; j++)
			printf("%d%c", v[i][j]+1, j == sz-1 ? '\n' : ' ');
	}
	return 0;
}

