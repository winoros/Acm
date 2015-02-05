/*
 * =====================================================================================
 *
 *       Filename:  2442.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/5 15:18:04
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

int data[2010];
int data2[2010];
priority_queue <int> q;

void MAIN() {
	int n, m;
	scanf("%d%d", &n, &m);
	while(!q.empty())
		q.pop();
	for(int i = 0; i < m; ++i)
		scanf("%d", &data[i]);
	sort(data, data+m);
	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < m; ++j)
			scanf("%d", &data2[j]);
		sort(data2, data2+m);
		while(!q.empty())
			q.pop();
		for(int j = 0; j < m; ++j)
			q.push(data2[0]+data[j]);
		for(int j = 1; j < m; ++j)
			for(int k = 0; k < m; ++k) {
				int tmp = data2[j] +data[k];
				if(tmp >= q.top())
					break;
				q.pop();
				q.push(tmp);
			}
		for(int j = m-1; j >= 0; --j) {
			data[j] = q.top();
			q.pop();
		}
	}
	for(int i = 0; i < m; ++i)
		printf("%d%c", data[i], i == m-1 ? '\n' : ' ');
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--)
		MAIN();
	return 0;
}
