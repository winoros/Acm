/*===============================================================
*   
*   FILE NAME:  1009.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       08/22/2014 02:16:07
*   EMAIL:      winoros@gmail.com
*   Description:solve the 1009th problem of Ural 
*
*
================================================================*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll com[20][20];

void make_com() {
	com[0][0] = com[1][0] = com[1][1] = com[0][1] = 1;
	for(int i = 2; i < 20; i++) {
		com[i][0] = com[i][i] = 1;
		for(int j = 1; j < i; j++)
			com[i][j] = com[i-1][j-1] + com[i-1][j];
	}
}

int main() {
	int n, k;
	ll mi[20];
	mi[0] = 1;
	scanf("%d%d", &n, &k);
	for(int i = 1; i < 20; i++) mi[i] = mi[i-1] * (k-1);
	make_com();
	ll ans = 0;
	for(int i = 0; i <= n/2 + (n&1); i++) {
	//	printf("%d %d\n", com[n-i-1][i], mi[n-i]);
		ans += com[n-i][i] * mi[n-i];
	}
	cout << ans << endl;
	return 0;
}
