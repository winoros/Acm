/*===============================================================
*   
*   FILE NAME:  100624a.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       03/07/2015 13:14:22
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
#include <bits/stdc++.h>

bool reach[1<<20];
int a[21][21];

void MAIN() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);
    memset(reach, false, sizeof reach);
    reach[(1<<n)-1] = true;
    for(int now = (1<<n)-1; now > 0; --now) {
        if(!reach[now])
            continue;
        for(int j = 0; j < n; ++j) {
            if(1 & (now>>j)) {
                int bet = 0;
                for(int k = 0; k < n; ++k)
                    if(1 & (now>>k))
                        bet += a[j][k];
                if(bet > 0)
                    reach[now - (1<<j)] = true;
            }
        }
    }
	bool exist = false;
    for(int i = 0; i < n; ++i)
        if(reach[(1<<i)]) {
			exist = true;
            printf("%d ", i+1);
		}
	if(!exist)
		puts("0");
	else
		puts("");
}

int main() {
//	freopen("2.in", "r", stdin);
//	freopen("out.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    while(n--)
        MAIN();
    return 0;
}
