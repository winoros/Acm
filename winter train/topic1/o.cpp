/*===============================================================
*   
*   FILE NAME:  o.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       01/26/2015 15:45:58
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
#include <bits/stdc++.h>

using namespace std;

int a[110];
bool used[110];

int erase(int begin_pos, int len) {
	int first_max = 0, pos = -1;
	for(int i = 0; i < len; ++i)
		if(!used[(begin_pos+i) %len] && a[(begin_pos+i) %len] > first_max)
			first_max = a[(begin_pos+i) %len], pos = (begin_pos+i) %len;
	return pos;
}

void MAIN() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);
	int ans = 1, pos = 0;
	memset(used, 0, sizeof used);
	for(pos = erase(pos, n); pos != m; pos = erase(pos, n))
		++ans, used[pos] = true;
	printf("%d\n", ans);
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--)
		MAIN();
	return 0;
}
