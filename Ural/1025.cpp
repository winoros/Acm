/*===============================================================
*   
*   FILE NAME:  1025.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       08/22/2014 00:05:01
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
#include <bits/stdc++.h>

using namespace std;

int a[200];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	sort(a, a+n);
	int ans = 0;
	for(int i = 0; i < n/2+1; i++)
		ans += a[i]/2+1;
	printf("%d\n", ans);
	return 0;
}
