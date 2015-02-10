/*===============================================================
*   
*   FILE NAME:  a.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       02/10/2015 10:56:23
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
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

int p[300010], cnt[300010], tot[300010];

int find(int x) {
	int tmp = p[x];
	if(x == p[x]) 
		return x;
	else {
		p[x] = find(p[x]);
		cnt[x] += cnt[tmp];
		return p[x];
	}
}

void merge(int x, int y) {
	int px = find(x), py = find(y);
	if(px == py)
		return ;
	p[px] = py;
	cnt[px] += tot[py];
	tot[py] += tot[px];
}

void MAIN() {
	for(int i = 1; i <= 300000; ++i)
		p[i] = i, cnt[i] = 0, tot[i] = 1;
	int m;
	scanf("%d", &m);
	char str[5];
	int x, y;
	while(m--) {
		scanf("%s%d", str, &x);
		if(str[0] == 'C') {
			find(x);
			printf("%d\n", cnt[x]);
		} else {
			scanf("%d", &y);
			merge(x, y);
		}
	}
}

int main() {
	MAIN();
	return 0;
}
