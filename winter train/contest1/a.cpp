/*===============================================================
*   
*   FILE NAME:  a.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       02/16/2015 14:36:21
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
#include <bits/stdc++.h>

using namespace std;

long long get(int l, int r) {
	if(r-l+1 == 2)
		return l*1LL*r;
	if(r-l+1 == 1)
		return 0;
	int m = (l+r)>>1;
	return get(l, m) + get(m+1, r);
}

void MAIN() {
	int n;
	scanf("%d", &n);
	printf("%lld\n", get(1, n));
}

int main() {
	MAIN();
	return 0;
}
