/*===============================================================
*   
*   FILE NAME:  1086.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       08/23/2014 20:40:21
*   EMAIL:      winoros@gmail.com
*   Description:solve the 1086th problem of Ural  
*
*
================================================================*/
#include <bits/stdc++.h>

using namespace std;

int prime[20000];
bool used[200001];

void make_prime() {
	for(int i = 2; i <= 200000; i++) {
		if(used[i]) continue;
		for(int j = 2*i; j <= 200000; j+= i)
			used[j] = true;
	}
	int len = 0;
	for(int i =2; i <= 200000; i++)
		if(!used[i])
			prime[len++] = i;
}

int main() {
	make_prime();
	int nn;
	scanf("%d", &nn);
	while(nn--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", prime[n-1]);
	}
	return 0;
}
