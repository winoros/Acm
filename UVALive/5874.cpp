/*
 * =====================================================================================
 *
 *       Filename:  5874.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/12 15:40:59
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

vector<int> v[410];
int pre[410];
bool flag[410];

bool find(int x) {
    int sz = v[x].size();
    for(int i = 0; i < sz; ++i) {
        if(!flag[v[x][i]]) {
            flag[v[x][i]] = true;
            if(pre[v[x][i]] == -1 || find(pre[v[x][i]])) {
                pre[v[x][i]] = x;
                return true;
            }
        }
    }
    return false;
}

int hungry(int n) {
    int ans = 0;
    memset(pre, -1, sizeof(pre));
    for(int i = 0; i < n; ++i) {
        memset(flag, 0, sizeof(flag));
        if(find(i)) ans++;
    }
    return ans;
}

int num[410];
bool ok[100010];

void MAIN() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", &num[i]);
	memset(ok, false, sizeof ok);
	for(int i = 0, tmp; i < m; ++i) {
		scanf("%d", &tmp);
		ok[tmp] = true;
	}
	for(int i = 0; i < n; ++i)
		v[i].clear();
	for(int i = 0; i < n; ++i)
		for(int j = i+1; j < n; ++j)
			if(ok[num[i]+num[j]])
				v[i].push_back(j), v[j].push_back(i);
	printf("%d\n", hungry(n)/2);
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--)
		MAIN();
	return 0;
}
