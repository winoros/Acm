/*===============================================================
*   
*   FILE NAME:  1052.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       08/25/2014 16:53:11
*   EMAIL:      winoros@gmail.com
*   Description:solve the 1052th problem of Ural
*
*
================================================================*/
/* 判断多点共线 */
#include <bits/stdc++.h>

using namespace std;

struct Point {
	int x, y;
};

Point p[210];

bool check(int i, int j, int k) {
	return (p[i].x-p[j].x)*(p[i].y-p[k].y)-(p[i].x-p[k].x)*(p[i].y-p[j].y) == 0;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d%d", &p[i].x, &p[i].y);
	int ans = 2;
	for(int i = 0; i < n; i++) 
		for(int j = i+1; j < n; j++) {
			int tmp = 2;
			for(int k = j+1; k < n; k++)
				if(check(i, j, k)) 
					tmp++;
			ans = max(ans, tmp);
		}
	printf("%d\n", ans);
	return 0;
}
