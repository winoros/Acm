/*===============================================================
*   
*   FILE NAME:  5870.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       02/12/2015 12:50:25
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
#include <bits/stdc++.h>

using namespace std;

int a[20010];

void MAIN() {
	int n;
	char str[110];
	scanf("%s", str);
	n = strlen(str);
	int len = 0;
	a[len++] = str[0]-'0';
	int maxx = a[0];
	for(int i = 1, tmp; i < n; ++i) {
		tmp = str[i] - '0';
		maxx = max(maxx, tmp);
		if(abs(tmp - a[len-1]) > 1) {
			int delta = (tmp-a[len-1]) > 0 ? 1 : -1;
			for(; a[len-1] != tmp; ++len)
				a[len] = a[len-1] + delta;
		} else
			a[len++] = tmp;
	}
	for(; maxx > 0; --maxx) {
		for(int i = 0; i < len; ++i)
			if(a[i] >= maxx)
				putchar('+');
			else
				putchar('*');
		puts("");
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--)
		MAIN();
	return 0;
}
