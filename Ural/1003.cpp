/*===============================================================
*   
*   FILE NAME:  1003.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       08/30/2014 15:08:34
*   EMAIL:      winoros@gmail.com
*   Description:solve the 1003th problem of Ural
*
*
================================================================*/
#include <bits/stdc++.h>

using namespace std;

int p[30000];

inline int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int l[5001], r[5001];
int a[10001];
char str[5001][6];

int main() {
    int len, n;
	while(scanf("%d", &len) && len != -1) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d%d%s", &l[i], &r[i], str[i]);
			a[i<<1] = l[i], a[i<<1|1] = r[i];
		}
		sort(a, a+n*2);
		int new_len = unique(a, a+n*2) - a;
		a[++new_len] = 1e9+7;
		for(int i = 0; i < 20100; i++)
			p[i] = i;
		bool ok = false;
		for(int i = 0; i < n; i++) {
			if(l[i] < 0 || r[i] > len) {
				printf("%d\n", i);
				ok = true;
				break;
			}
			int ll = lower_bound(a, a+new_len, l[i]) - a + 1;
			int rr = lower_bound(a, a+new_len, r[i]) - a + 1;
			int lp = find(ll-1), rp = find(rr);
			int llp = find(ll-1+new_len), rrp = find(rr+new_len);
			if(str[i][0] == 'e') {
				if(rp == llp || rrp == lp) {
					printf("%d\n", i);
					ok = true;
					break;
				} 
				if(rp != lp)
					p[rp] = lp;
				if(rrp != llp)
					p[rrp] = llp;
			} else {
				if(rp == lp || rrp == llp) {
					printf("%d\n", i);
					ok = true;
					break;
				}
				if(rp != llp)
					p[rp] = llp;
				if(rrp != lp)
					p[rrp] = lp;
			}
		}
		if(!ok)
			printf("%d\n", n);
	}
    return 0;
}
